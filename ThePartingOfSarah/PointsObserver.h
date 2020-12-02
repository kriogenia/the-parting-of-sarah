#pragma once

#include "Enemy.h"
#include "Observer.h"

class PointsObserver :
    public Observer
{
public:
    PointsObserver(int* points);
    /* Observer */
    void notify(eObserverMessages message, void* publisher = nullptr) override;
private:
    int* points;
};

