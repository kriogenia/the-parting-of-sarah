#pragma once

#include "Boss.h"

constexpr auto PERA_HP = 29;
constexpr auto PERA_SPEED = 3;
constexpr auto PERA_MAX_SPEED = 5;

enum ePeraActions {
    FLY,
    REFLECT,
    SPRINT,
    THROW_MINES
};

class Pera :
    public Boss
{
public:
    Pera(float x, float y, Environment* room, Game* game);
    ~Pera();
    /* Actor */
    //void update() override;
    //void collisionedWith(Actor* actor) override;

private:
    /* Character */
    void importAnimations() override;
    /* Enemy*/
    void setOrientation() override {};
    /* Boss */
    void doAction() override;
    /* Pool of actions of the boss */
    void reflect();
    void sprint();
    void throwMines();
    /* Action animations */
    Animation* reflectAnimation;
    Animation* sprintAnimation;
    Animation* throwMinesAnimation;

};

