#pragma once

#include "Enemy.h"
#include "Observer.h"

class PointsObserver :
    public Observer
{
public:
    PointsObserver(int* points);

    void notify(eObserverMessages message, void* publisher = nullptr) override;
private:
    int* points;
};

