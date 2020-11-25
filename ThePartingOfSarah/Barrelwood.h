#pragma once

#include "Boss.h"
#include "Player.h"

constexpr auto BARRELWOOD_HP = 25;
constexpr auto BARRELWOOD_SPEED = 3;
constexpr auto BARRELWOOD_PROJECTILE_SIZE = 13;

enum eBarrelwoodActions {
    SPREADING_ACID,
    ROLLING,
    SMOKING
};

class Barrelwood :
    public Boss
{
public:
    Barrelwood(float x, float y, Environment* room, Game* game);
    ~Barrelwood();

private:
    /* Character */
    void importAnimations() override;
    /* Enemy */
    void setMovement() override;
    void setOrientation() override {};
    /* Boss */
    void doAction() override;
    /* Pool of actions of the boss */
    void spreadAcid();
    void roll();
    void smoke();
    /* Action animations */
    Animation* rollXAnimation;
    Animation* rollYAnimation;
    Animation* smokeAnimation;
    Animation* spreadAnimation;
    /* Direction */
    int directionX;
    int directionY;

    /* Internal classes */
    class AcidTile :
        public Tile
    {
    public:
        AcidTile(float x, float y, Game* game);
        void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;
        void collisionedWith(Actor* actor) override;
    private:
        int time;
    };

    class SmokeProjectile :
        public Projectile
    {
    public:
        SmokeProjectile(float x, float y, Game* game);
        void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;
    private:
        Animation* animation;
    };
};

