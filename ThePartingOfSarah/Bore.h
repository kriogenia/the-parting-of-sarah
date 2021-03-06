#pragma once

#include "Boss.h"

/* Attributes */
constexpr auto BORE_HP = 40;
constexpr auto BORE_SPEED = 1;
constexpr auto BORE_HEALING = 2;
/* Projectile attributes */
constexpr auto BORE_PROJECTILE_SIZE = 8;
constexpr auto BORE_PROJECTILE_SPEED = 3;
constexpr auto BORE_PROJECTILE_LIFE = 150;          // 5s
/* Franky attributes */
constexpr auto FRANKY_SPEED = 2;
constexpr auto FRANKY_HP = 3;

enum eBoreMoveset {
    SHOOT,
    SLEEP,
    SUMMON_FRANKY
};

class Bore :
    public Boss
{
public:
    Bore(float x, float y, Environment* room, Game* game);
    ~Bore();
    /* Game cycle */
    void update() override;

private:
    /* Character */
    void importAnimations() override;
    void setOrientation() override {};
    /* Boss */
    void doAction() override;
    /* Moveset */
    void shoot();
    void sleep();
    void summonFranky();
    /* Action animations */
    Animation* shootAnimation;
    Animation* sleepAnimation;
    Animation* summonFrankyAnimation;

    /***************
    Internal classes
    ****************/

    class Franky :
        public Enemy
    {
    public:
        Franky(float x, float y, Environment* room, Game* game);
    private:
        void importAnimations() override;
        void death() override;
    };

    /*****************************/

    class ChasingProjectile :
        public Projectile
    {
    public:
        ChasingProjectile(float x, float y, Actor* player, Game* game);
        void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;
    private:
        void update();
        Actor* player;
        int aliveTime;
    };
};

