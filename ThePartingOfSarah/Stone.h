#pragma once

#include "Enemy.h"

/* Large rock attributes */
constexpr auto ROCK_LARGE_POINTS = 3;
constexpr auto ROCK_LARGE_HP = 6;
constexpr auto ROCK_LARGE_SPEED = 1;
/* Medium rock attributes */
constexpr auto ROCK_MEDIUM_POINTS = 2;
constexpr auto ROCK_MEDIUM_HP = 4;
constexpr auto ROCK_MEDIUM_SPEED = 1.5;
/* Small rock attributes */
constexpr auto ROCK_SMALL_POINTS = 1;
constexpr auto ROCK_SMALL_HP = 2;
constexpr auto ROCK_SMALL_SPEED = 2;

class Stone :
    public Enemy
{
public:
    Stone(float x, float y, Environment* room, Game* game);
private:
    /* Character */
    void importAnimations() override;
    /* Enemy */
    void death() override;

    /***************
    Internal classes
    ****************/

    class MediumStone :
        public Enemy
    {
    public:
        MediumStone(float x, float y, Environment* room, Game* game);
    private:
        void importAnimations() override;
        void death() override;
    };

    /****************/

    class SmallStone :
        public Enemy
    {
    public:
        SmallStone(float x, float y, Environment* room, Game* game);
    private:
        void importAnimations() override;
        void death() override;
    };
};
