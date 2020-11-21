#pragma once

#include "Enemy.h"

enum eBossList {
    LITOST
};

class Boss :
    public Enemy
{
public:
    Boss(string filename, float x, float y, int width, int height, Environment* room, Game* game);
    ~Boss();

    string name;
    string subtitle;
private:
    void setAction(bool endAction) override;

    void death() override;
    void hit() override;

    // list of actions
};

