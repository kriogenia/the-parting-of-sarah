#pragma once

#include "Actor.h"

class Space
{
public:
	Space();

	void update();

	void addDynamicActor(Actor* actor);
	void addStaticActor(Actor* actor);
	void removeDynamicActor(Actor* actor);
	void removeStaticActor(Actor* actor);

	list<Actor*> dynamicActors;
	list<Actor*> staticActors;

private:
	void updateMovementUp(Actor* dynamicActor);
	void updateMovementLeft(Actor* dynamicActor);
	void updateMovementRight(Actor* dynamicActor);
	void updateMovementBottom(Actor* dynamicActor);
};

