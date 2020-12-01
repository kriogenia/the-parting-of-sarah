#pragma once

#include "Enemy.h"

class Stone :
    public Enemy
{
public:
    Stone(float x, float y, Environment* room, Game* game);
private:
    void importAnimations() override;

    void death() override;

    /* Medium Stone */
    class MediumStone :
        public Enemy
    {
    public:
        MediumStone(float x, float y, Environment* room, Game* game);
    private:
        void importAnimations() override;

        void death() override;
    };

    /* Small Stone */
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
