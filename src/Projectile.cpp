#include "../include/Projectile.h"
#include "../include/Globals.h"
#include "../include/UI.h"

Projectile::Projectile(Texture2D& t_texture, Vector2 t_pos)
    : texture(t_texture)
{
    position = t_pos;
    GameObject::init(position, WHITE);
    radius = 15.0f;

    sprite = std::make_shared<Drawable>(position, active);
    sprite->setTexture(texture);
    active = true;
    scale = 1;
}

void Projectile::shoot(Effect &t_effects, Vector2 t_dir)
{
    effects = t_effects; 
    spawnPos = position;
    baseVelocity = Vector2Scale(Vector2Normalize(t_dir), effects.shotSpeed);

    active = true;
}

void Projectile::input()
{
    if (!moving)
    {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && !UI::mouseInUI())
        {
            release();
        }
    }
}

void Projectile::release()
{
    if (effects.shotSpeed > 0)
    {
        strokes++;
        moving = true;
        // Get Direction
        direction = Vector2Subtract(GetMousePosition(), position);
        direction = Vector2Scale(Vector2Normalize(direction), effects.shotSpeed*20);
        baseVelocity = direction;
        time = 0.0f;
    }
}

void Projectile::update(const std::vector<std::shared_ptr<Obstacle>>& obstacles)
{
    input();

    if (!moving) return;

    time += GetFrameTime();

    // Give the ball an effect
    effects.movementEffect(this);

    // combine the direction velocity with the effect's velocity
    Vector2 combinedVel = Vector2Add(baseVelocity, effectVelocity);

    // —————————————————————————
    // 5) collision‑safe sub‑stepping
    // total distance this frame:
    float moveDist = Vector2Length(combinedVel) * GetFrameTime();
    int   steps    = (int)ceil(moveDist / (radius * 0.5f));
    steps = (steps < 1) ? 1 : steps;

    // per‑step displacement = combinedVel * (dt/steps)
    Vector2 stepDisp = Vector2Scale(combinedVel, GetFrameTime()/(float)steps);

    for (int i = 0; i < steps; i++)
    {
        position = Vector2Add(position, stepDisp);

        for (auto& ob : obstacles)
        {
            if (ob->isActive())
            {
                CollisionInfo info =
                CollisionEffects::getCircleRecCollisionSide(position, radius, ob->getRect());
                if (info.side != CollisionSide::SIDE_NONE)
                {
                    // push‑out & bounce
                    Vector2 diff   = Vector2Subtract(position, info.contactPoint);
                    Vector2 normal = Vector2Normalize(diff);
                    position = Vector2Add(info.contactPoint, Vector2Scale(normal, radius));
                    onCollision(ob, info);
                    goto doneStepping;
                }
            }
        }
    }
doneStepping:
    // Apply friction
    baseVelocity = Vector2Scale(baseVelocity, FRICTION);

    // 7) stop if you’ve slowed to a crawl
    if (Vector2Length(baseVelocity) * GetFrameTime() <= 0.1f)
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
        // Draw aim line
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
    else
    {
        DrawCircleV(position, radius * scale, color);
    }
}

void Projectile::reset()
{
    strokes = 0; 
    scale = 1; 
    active = true; 
    baseVelocity = {0, 0}; 
    effectVelocity = {0, 0};
    effects.shotSpeed = 0;

    effects.movementEffect = MovementEffects::defaultMovement;
    effects.onHitEffect = CollisionEffects::defaultHit;
}