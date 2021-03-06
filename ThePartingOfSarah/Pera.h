#pragma once

#include "Boss.h"
#include "Player.h"

/* Attributes */
constexpr auto PERA_HP = 29;
constexpr auto PERA_SPEED = 2;
constexpr auto PERA_MAX_SPEED = 4;
constexpr auto PERA_MINE_COOLDOWN = 15;
/* Files */
constexpr auto DEFLECTED_PROJECTILE_FILE = "res/sprites/pera/Reflected_Projectile.png";

enum ePeraMoveset {
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
    /* Game cycle */
    void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;
    void update() override;
    /* Actor */
    void collisionedWith(Actor* actor) override;

private:
    /* Character */
    void importAnimations() override;
    /* Enemy*/
    void setMovement() override;
    void setOrientation() override {};
    /* Boss */
    void doAction() override;
    /* Moveset */
    void reflect();
    void sprint();
    void throwMines();
    /* Action animations */
    Animation* reflectAnimation;
    Animation* sprintAnimation;
    Animation* throwMinesAnimation;
    /* Attributes */
    int mineCooldown;

    /***************
    Internal classes
    ****************/

    class MineTile :
        public Tile
    {
    public:
        MineTile(float x, float y, Game* game);
        void draw(int scrollX = 0, int scrollY = 0, float rotation = 0.0) override;
        void collisionedWith(Actor* actor) override;
    private:
        int time;
    };

};

