#include "../include/Projectile.h"
#include "../include/Globals.h"

Projectile::Projectile(Texture2D& t_texture, Vector2 t_pos)
    : texture(t_texture)
{
    position = t_pos;
    GameObject::init(position, WHITE);
    radius = 15.0f;

    sprite = std::make_shared<Drawable>(position, active);
    sprite->setTexture(texture);
    active = true;
}

void Projectile::shoot(Effect &t_effects, Vector2 t_dir)
{
    effects = t_effects; 
    spawnPos = position;
    velocity = Vector2Scale(Vector2Normalize(t_dir), effects.shotSpeed);

    active = true;
}

void Projectile::input()
{
    if (!moving)
    {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            printf("\nrelease\n\n");
            release();
        }

        if (IsKeyReleased(KEY_W))
        {
            effects.shotSpeed += 10;
        }
        else if (IsKeyReleased(KEY_S))
        {
            effects.shotSpeed -= 10;
        }
    }
}

void Projectile::release()
{
    moving = true;
    // Get Direction
    direction = Vector2Subtract(position, GetMousePosition());
    direction = Vector2Scale(Vector2Normalize(direction), effects.shotSpeed);
    velocity = direction;
}

void Projectile::update(const std::vector<std::shared_ptr<Obstacle>>& obstacles)
{
    input();

    if (!moving) return;

    // Determine how many sub‑steps we'll need.
    // Here we cap each mini‑step to at most half the radius.
    float moveDist = Vector2Length(velocity);
    int steps = (int)ceil(moveDist / (radius * 0.5f));
    if (steps < 1) steps = 1;

    // 2) Compute the per‑step velocity
    Vector2 stepVel = Vector2Scale(velocity, 1.0f/steps);

    // March along in tiny increments, testing collisions at each
    for (int i = 0; i < steps; i++)
    {
        // Continue
        position = Vector2Add(position, stepVel);

        // Test against every obstacle
        for (auto& ob : obstacles)
        {
            CollisionInfo info = CollisionEffects::getCircleRecCollisionSide(position, radius, ob->getRect());

            if (info.side != CollisionSide::SIDE_NONE)
            {
                // Push the ball out so it's flush against the box
                Vector2 diff   = Vector2Subtract(position, info.contactPoint);
                Vector2 normal = Vector2Normalize(diff);
                position = Vector2Add(info.contactPoint, Vector2Scale(normal, radius));

                // Respond
                onCollision(ob, info);

                goto doneStepping;
            }
        }
    }

doneStepping:
    // Apply friction once per frame
    velocity = Vector2Scale(velocity, FRICTION);

    // If you've slowed to almost zero, stop
    if (Vector2Length(velocity) <= 0.1f)
        moving = false;
}


void Projectile::onCollision(const std::shared_ptr<Obstacle>& t_box, CollisionInfo t_result)
{
    effects.onHitEffect(this, t_box, t_result);
}

void Projectile::draw()
{
    if (active)
    {
        DrawCircleV(position, radius, color);

        // Draw drag line
        if (!moving)
        {
            Vector2 dir = Vector2Subtract(GetMousePosition(), position);
            float dirLen = Vector2Length(dir);
            if (dirLen > 0)
            {
                dir = Vector2Scale(dir, 1.0f/dirLen);
            }
            Vector2 offset = Vector2Scale(dir, effects.shotSpeed * 2);
            Vector2 end = Vector2Add(position, offset);
            DrawLineEx(position, end, 5, color);
        }
    }
}