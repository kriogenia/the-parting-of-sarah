#pragma once

#include "Enemy.h"

/* Default boss attributes */
constexpr auto DEFAULT_BOSS_ACTIONS = 3;
constexpr auto DEFAULT_BOSS_CD = 60;
constexpr auto DEFAULT_BOSS_POINTS = 50;

/* List of bosses */
enum eBossList {
    BARRELWOOD,
    BORE,
    LITOST,
    PERA
};

/* interface */
class Boss :
    public Enemy
{
public:
    Boss(string filename, float x, float y, int width, int height, Environment* room, Game* game);
    /* Game cycle */
    void update() override;
    /* Attributes */
    string name;
    string subtitle;
    int maxHp;
protected:
    /* Character */
    void setAction(bool endAction) override;
    /* Enemy */
    void death() override;
    void hit() override;
    /* Boss interface */
    virtual void doAction() = 0;
    /* Counter */
    int cooldown;
};

