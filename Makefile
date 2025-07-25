# ----------------------------------------
# Silence command echoing
# ----------------------------------------
.SILENT:

# ----------------------------------------
# General Configuration
# ----------------------------------------
include toolchain/resources.mk
include toolchain/messages.mk

# ----------------------------------------
# Default Compiler and Directories
# ----------------------------------------
CC                     := g++

DEBUG_DIR              := ./debug
RELEASE_DIR            := ./release
OBJECTS_DIR            := ./objects
SRC_DIR                := ./src
WEB_DIR                := ./web
RAYLIB_DIR             := ./raylib
RAYLIB_BUILD_DIR       := $(RAYLIB_DIR)/build
RAYLIB_BUILD_DIR_WEB   := $(RAYLIB_DIR)/build_web

RAYLIB_INCLUDE         := $(RAYLIB_DIR)/src
RAYLIB_LIBRARY         := $(RAYLIB_BUILD_DIR)/raylib
RAYLIB_LIBRARY_WEB     := $(RAYLIB_BUILD_DIR_WEB)/raylib
EMSDK_DIR              := ./emsdk

HTML_TEMPLATE          := ./template/template.html

# ----------------------------------------
# Build Types
# ----------------------------------------
BUILD_TYPE             := "all"
BUILD                  := "build"
BUILD_WEB              := "build_web"

# ----------------------------------------
# OS Detection
# ----------------------------------------
UNAME_S                := $(shell uname -s)
IS_WINDOWS             := $(if $(findstring MINGW,$(UNAME_S)),TRUE,FALSE)
IS_LINUX               := $(if $(findstring Linux,$(UNAME_S)),TRUE,FALSE)
IS_WSL                 := $(shell grep -qi Microsoft /proc/version && echo TRUE || echo FALSE)
IS_MACOS               := $(if $(findstring Darwin,$(UNAME_S)),TRUE,FALSE)

# ----------------------------------------
# Compiler Flags
# ----------------------------------------
INCLUDES               := -I. -I$(RAYLIB_INCLUDE)
LIBS                   := -L$(RAYLIB_LIBRARY)
LIBRARIES              := -lraylib -lm -lpthread

CONFIG                 ?= debug
OPTIMISATION_LEVEL     ?= 2

ifeq ($(CONFIG), debug)
	BUILD_DIR := $(DEBUG_DIR)
	CFLAGS := -std=c++17 -Wall -g -DDEBUG $(INCLUDES)
else ifeq ($(CONFIG), release)
	BUILD_DIR := $(RELEASE_DIR)
	CFLAGS := -std=c++17 -O$(OPTIMISATION_LEVEL) -DNDEBUG $(INCLUDES)
else
	$(error Invalid CONFIG value: $(CONFIG))
endif

# ----------------------------------------
# Platform-specific
# ----------------------------------------
ifeq ($(IS_WINDOWS),TRUE)
	TOOLCHAIN  := ./toolchain/toolchain_windows.sh
	LIBRARIES += -lglfw3 -lopengl32 -lgdi32 -lwinmm
	TARGET     := $(BUILD_DIR)/game.exe
	WEB_APP    := start http://localhost:8000/
else ifeq ($(IS_MACOS),TRUE)
	TOOLCHAIN  := ./toolchain/toolchain_macos.sh
	CC         := clang
	LIBRARIES += -framework IOKit -framework CoreFoundation -framework Cocoa -framework CoreGraphics
	TARGET     := $(BUILD_DIR)/game.bin
	WEB_APP    := open http://localhost:8000/
else ifeq ($(IS_WSL),TRUE)
	TOOLCHAIN  := ./toolchain/toolchain_linux.sh
	LIBRARIES += -lGL -ldl
	TARGET     := $(BUILD_DIR)/game.bin
	WEB_APP    := wslview http://localhost:8000/
else
	TOOLCHAIN  := ./toolchain/toolchain_linux.sh
	LIBRARIES += -lGL -ldl
	TARGET     := $(BUILD_DIR)/game.bin
	WEB_APP    := xdg-open http://localhost:8000/
endif

# ----------------------------------------
# Source Files
# ----------------------------------------
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/$(OBJECTS_DIR)/%.o)

# ----------------------------------------
# Build Targets
# ----------------------------------------

.PHONY: all
all: BUILD_TYPE := all
all: build run

$(BUILD_DIR)/$(OBJECTS_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)/$(OBJECTS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: ignore-build-dirs
ignore-build-dirs:
	@if [ -d "$(DIR)" ]; then \
		$(call INFO_MSG,"Directory : $(DIR) to ignore..."); \
		$(call INFO_MSG,$(MSG_IGNORE_CHANGES)); \
		(cd $(DIR) && \
		 git ls-files --error-unmatch * > /dev/null 2>&1 && \
		 git update-index --assume-unchanged * || \
		 $(call WARNING_MSG,$(MSG_IGNORE_UNTRACKED)); \
		); \
	else \
		$(call INFO_MSG,$(MSG_IGNORE_NONE)); \
	fi

.PHONY: build
build: BUILD_TYPE := build
build: install_toolchain
	$(call INFO_MSG,$(MSG_BUILD_START))
	$(MAKE) $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIBS) $(LIBRARIES)
	$(call SUCCESS_MSG,$(MSG_BUILD_END))

.PHONY: run
run:
	$(call INFO_MSG,$(MSG_RUN_BINARY))
	./$(TARGET)

.PHONY: build_web
build_web: BUILD_TYPE := build_web
build_web: install_toolchain
	$(call INFO_MSG,$(MSG_BUILD_WEB_START))
	rm -rf $(WEB_DIR)
	mkdir -p $(WEB_DIR)

	if [ -f "$(EMSDK_DIR)/emsdk_env.sh" ]; then \
		$(call INFO_MSG, $(MSG_BUILD_WEB_EMSDK)); \
		bash -i -c ' \
			source $(EMSDK_DIR)/emsdk_env.sh && \
			emcc ./src/*.cpp -o ./$(WEB_DIR)/index.html \
				-I. -I$(RAYLIB_INCLUDE) \
				-L$(RAYLIB_LIBRARY_WEB) \
				-lraylib \
				-s USE_GLFW=3 -s FULL_ES2=1 -s ASYNCIFY \
				-s EXPORTED_RUNTIME_METHODS=["HEAPF32"] \
				--shell-file $(HTML_TEMPLATE) \
				--preload-file resources@resources \
				-D WEB_BUILD; \
			STATUS=$$?; \
			if [ $$STATUS -eq 0 ]; then \
				echo "$(MSG_BUILD_WEB_END)"; \
			else \
				echo "$(MSG_BUILD_WEB_FAIL)"; \
			fi' \
	else \
		$(call ERROR_MSG, $(MSG_BUILD_WEB_EMSDK_FAIL)); \
	fi

.PHONY: run_web
run_web: build_web stop_web_server start_web_server
	$(WEB_APP)

.PHONY: stop_web_server
stop_web_server:
	$(call INFO_MSG,$(MSG_SERVER_CHECK))
	PID=$$(ps aux | grep '[h]ttp.server' | awk '{print $$2}'); \
	if [ -n "$$PID" ]; then \
    	kill $$PID; \
	fi

.PHONY: start_web_server
start_web_server:
	$(call INFO_MSG,$(MSG_SERVER_START))
	python3 -m http.server --directory $(WEB_DIR) &
	sleep 3

.PHONY: install_toolchain
install_toolchain:
	$(info BUILD_TYPE: $(BUILD_TYPE))
	$(info TARGET: $(TARGET))
	$(info TOOLCHAIN: $(TOOLCHAIN))

	if [ ! -f "$(TOOLCHAIN)" ]; then \
		$(call ERROR_MSG,$(MSG_TOOLCHAIN_NO_SCRIPT)); \
		exit 1; \
	else \
		$(call INFO_MSG,$(MSG_TOOLCHAIN_SCRIPT)); \
	fi

	if [ -d "$(RAYLIB_DIR)" ]; then \
		$(call INFO_MSG,$(MSG_TOOLCHAIN_FOUND)); \
		$(call SUCCESS_MSG,$(MSG_RAYLIB_FOUND)); \
	else \
		$(call INFO_MSG,$(MSG_TOOLCHAIN_NOT_FOUND)); \
		$(call INFO_MSG,$(MSG_TOOLCHAIN_NONE)); \
		$(call WARNING_MSG,$(MSG_RAYLIB_NONE)); \
		$(TOOLCHAIN) $$(pwd) "$(BUILD)"; \
		$(MAKE) ignore-build-dirs BUILD="$(BUILD)"; \
	fi

	if [ "$(BUILD_TYPE)" = "$(BUILD_WEB)" ]; then \
		if [ -d "$(EMSDK_DIR)" ]; then \
			$(call INFO_MSG,$(MSG_TOOLCHAIN_FOUND)); \
			$(call SUCCESS_MSG,$(MSG_EMSDK_FOUND)); \
		else \
			$(call INFO_MSG,$(MSG_TOOLCHAIN_NOT_FOUND)); \
			$(call INFO_MSG,$(MSG_TOOLCHAIN_NONE)); \
			$(call WARNING_MSG,$(MSG_EMSDK_NONE)); \
			$(TOOLCHAIN) $$(pwd) "$(BUILD_WEB)"; \
			$(MAKE) ignore-build-dirs BUILD="$(BUILD_WEB)"; \
		fi; \
	fi

.PHONY: clean
clean:
	$(call INFO_MSG,$(MSG_CLEAN))
	rm -rf $(DEBUG_DIR) $(RELEASE_DIR) $(WEB_DIR)

.PHONY: clean_toolchain
clean_toolchain:
	$(call INFO_MSG,$(MSG_CLEAN_TOOLCHAIN))
	rm -rf $(RAYLIB_DIR) $(EMSDK_DIR)
