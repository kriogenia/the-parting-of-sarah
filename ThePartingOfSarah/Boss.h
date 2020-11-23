#pragma once

#include "Enemy.h"

constexpr auto DEFAULT_BOSS_CD = 60;

enum eBossList {
    LITOST
};

class Boss :
    public Enemy
{
public:
    Boss(string filename, float x, float y, int width, int height, Environment* room, Game* game);

    void update() override;

    string name;
    string subtitle;
    int maxHp;
protected:
    void setAction(bool endAction) override;

    void death() override;
    void hit() override;

    virtual void doAction() = 0;

    int cooldown;

    /*
    setAction -> un cooldown, al acabar -> lanza una de las tres acciones (aleatoriamente)
    las tres acciones ser�n m�todos (o funcional si es sencillo)
    cada acci�n, una animaci�n sin bucle
        acciones: 
        - cuatro colmillos en diferentes direcciones que se lanzan en l�nea recta
        - misil teledirigido
        - escudo
    */
};

