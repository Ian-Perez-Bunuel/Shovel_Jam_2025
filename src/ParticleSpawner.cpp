#include "../include/ParticleSpawner.h"
#include <raymath.h>

void ParticleSpawner::setValues(Vector2 t_pos, int t_angleLeeway, float t_dirAngle)
{
    position = t_pos;
    angleLeeway = t_angleLeeway;
    dirAngle = t_dirAngle;
}

void ParticleSpawner::addColor(Color t_color)
{
    colors.push_back(t_color);
}

void ParticleSpawner::spawn()
{
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        float randDir = randomizeDir();
        int randSpeed = (rand() % 3) + 3;
        int randSize = (rand() % 4) + 4;
        Color randColor = randomizeColor();

        particles.push_back(Particle(position, randSize, randSpeed, randDir, randColor));
    }

    active = true;
}

void ParticleSpawner::spawn(int t_amount)
{
    for (int iteration = 0; iteration < t_amount; iteration++)
    {
        for (int i = 0; i < MAX_PARTICLES; i++)
        {
            float randDir = randomizeDir();
            int randSpeed = (rand() % 3) + 3;
            int randSize = (rand() % 4) + 4;
            Color randColor = randomizeColor();

            particles.push_back(Particle(position, randSize, randSpeed, randDir, randColor));
        }
    }
    active = true;
}

void ParticleSpawner::circularSpawn(int t_amount, float t_radius)
{
    for (int iteration = 0; iteration < t_amount; iteration++)
    {
        for (int i = 0; i < MAX_PARTICLES; i++)
        {
            float randDir = randomizeDir();
            Vector2 randPos = posOnCircle(randDir, t_radius);
            int randSpeed = (rand() % 3) + 3;
            int randSize = (rand() % 4) + 4;
            Color randColor = randomizeColor();

            particles.push_back(Particle(randPos, randSize, randSpeed, randDir, randColor));
        }
    }

    active = true;
}

void ParticleSpawner::implode(int t_amount, float t_radius)
{
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        // Start position on a circle (optional, or use 'center')
        float randAngle = randomizeDir(); // or random float from 0 to 2*PI
        Vector2 randPos = posOnCircle(randAngle, t_radius); // particle spawn position

        // Calculate direction towards target
        Vector2 dirToTarget = Vector2Subtract(position, randPos);
        float angleToTarget = atan2f(dirToTarget.y, dirToTarget.x); // radians

        int randSpeed = (rand() % 3) + 3;
        int randSize = (rand() % 4) + 4;
        Color randColor = randomizeColor();

        // Create particle with angle *towards* the target
        particles.push_back(Particle(randPos, randSize, randSpeed, angleToTarget, randColor));
    }
    

    active = true;
}

bool ParticleSpawner::checkIfParticalsActive()
{
    for (Particle& p : particles)
    {
        if (p.isActive())
        {
            return false; // At least one particle  is active
        }
    }

    // No particles are active
    return true;
}

void ParticleSpawner::update()
{
    if (checkIfParticalsActive())
    {
        particles.clear();
        active = false;
    }
    
    if (active && !paused)
    {
        for (Particle& p : particles)
        {
            if (p.isActive())
            {
                p.move();
            }
        }
    }
    else if (paused)
    {
        printf("Particles are paused");
    }
}

void ParticleSpawner::draw()
{
    for (Particle& p : particles)
    {
        if (p.isActive())
        {
            p.draw();
        }
    }
}

Vector2 ParticleSpawner::posOnCircle(float t_angle, float t_radius)
{
    Vector2 randPos = {0.0f, 0.0f};
    float randAngle = rand() % 360;
    t_angle = t_angle * DEG2RAD;

    randPos.x = position.x + t_radius * cos(t_angle);
    randPos.y = position.y + t_radius * sin(t_angle);


    return randPos;
}

float ParticleSpawner::randomizeDir()
{
    // Randomize direction
    float result = 0.0f;
    float randLeewat = rand() % angleLeeway;
    if (rand() % 2 == 0)
    {
        result = dirAngle + randLeewat;
    }
    else
    {
        result = dirAngle - randLeewat;
    }

    return result;
}

Color ParticleSpawner::randomizeColor()
{
    return colors[rand() % colors.size()];;
}