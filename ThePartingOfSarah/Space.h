#pragma once

#include "Actor.h"

class Space
{
public:
	Space();

	void update();

	void checkDynamicCollisions();

	void addDynamicActor(Actor* actor);
	void addFlyingDynamicActor(Actor* actor);
	void addStaticActor(Actor* actor);
	void addLowStaticActor(Actor* actor);

	void removeDynamicActor(Actor* actor);
	void removeFlyingDynamicActor(Actor* actor);
	void removeStaticActor(Actor* actor);
	void removeLowStaticActor(Actor* actor);

private:
	void updateMovementUp(Actor* dynamicActor, bool flying);
	void updateMovementLeft(Actor* dynamicActor, bool flying);
	void updateMovementRight(Actor* dynamicActor, bool flying);
	void updateMovementBottom(Actor* dynamicActor, bool flying);

	void checkCollisionUp(Actor* dynamicActor, Actor* staticActor, float* possibleMovement);
	void checkCollisionLeft(Actor* dynamicActor, Actor* staticActor, float* possibleMovement);
	void checkCollisionRight(Actor* dynamicActor, Actor* staticActor, float* possibleMovement);
	void checkCollisionDown(Actor* dynamicActor, Actor* staticActor, float* possibleMovement);

	list<Actor*> dynamicActors;
	list<Actor*> flyingDynamicActors;
	list<Actor*> staticActors;
	list<Actor*> lowStaticActors;
};

