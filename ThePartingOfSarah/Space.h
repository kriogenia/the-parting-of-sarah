#pragma once

#include "Actor.h"

class Space
{
public:
	Space() {};
	/* Game cycle */
	void update();
	void checkDynamicCollisions();
	/* Add actors */
	void addDynamicActor(Actor* actor);
	void addFlyingDynamicActor(Actor* actor);
	void addStaticActor(Actor* actor);
	void addLowStaticActor(Actor* actor);
	void addVirtualActor(Actor* actor);
	/* Remove actors */
	void removeDynamicActor(Actor* actor);
	void removeFlyingDynamicActor(Actor* actor);
	void removeStaticActor(Actor* actor);
	void removeLowStaticActor(Actor* actor);
	void removeVirtualActor(Actor* actor);

private:
	/* Actor movement update */
	void updateMovementUp(Actor* dynamicActor, bool flying);
	void updateMovementLeft(Actor* dynamicActor, bool flying);
	void updateMovementRight(Actor* dynamicActor, bool flying);
	void updateMovementBottom(Actor* dynamicActor, bool flying);
	/* Collisions check*/
	void checkCollisionUp(Actor* dynamicActor, Actor* staticActor, float* possibleMovement);
	void checkCollisionLeft(Actor* dynamicActor, Actor* staticActor, float* possibleMovement);
	void checkCollisionRight(Actor* dynamicActor, Actor* staticActor, float* possibleMovement);
	void checkCollisionDown(Actor* dynamicActor, Actor* staticActor, float* possibleMovement);
	/* Lists */
	list<Actor*> dynamicActors;
	list<Actor*> flyingDynamicActors;
	list<Actor*> staticActors;
	list<Actor*> lowStaticActors;
	list<Actor*> virtualActors;
};

