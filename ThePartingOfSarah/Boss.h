#pragma once

#include "Enemy.h"

constexpr auto DEFAULT_BOSS_ACTIONS = 3;
constexpr auto DEFAULT_BOSS_CD = 60;

enum eBossList {
    BARRELWOOD,
    LITOST,
    PERA
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
    las tres acciones serán métodos (o funcional si es sencillo)
    cada acción, una animación sin bucle
        acciones: 
        - cuatro colmillos en diferentes direcciones que se lanzan en línea recta
        - misil teledirigido
        - escudo
    */
};

