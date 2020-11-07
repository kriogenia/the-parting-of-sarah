#include "Space.h"

Space::Space() {
	dynamicActors.clear();
	staticActors.clear();
}

void Space::update() {
	for (auto const& actor : dynamicActors) {
		(actor->vx > 0) ? updateMovementRight(actor, false) : updateMovementLeft(actor, false);
		(actor->vy > 0) ? updateMovementBottom(actor, false) : updateMovementUp(actor, false);
	}
    for (auto const& actor : flyingDynamicActors) {
        (actor->vx > 0) ? updateMovementRight(actor, true) : updateMovementLeft(actor, true);
        (actor->vy > 0) ? updateMovementBottom(actor, true) : updateMovementUp(actor, true);
    }
}

void Space::addDynamicActor(Actor* actor) {
	dynamicActors.push_back(actor);
}

void Space::addFlyingDynamicActor(Actor* actor) {
    flyingDynamicActors.push_back(actor);
}

void Space::addStaticActor(Actor* actor) {
	staticActors.push_back(actor);
}

void Space::addLowStaticActor(Actor* actor) {
    lowStaticActors.push_back(actor);
}

void Space::removeDynamicActor(Actor* actor) {
	dynamicActors.remove(actor);
}

void Space::removeFlyingDynamicActor(Actor* actor) {
    flyingDynamicActors.remove(actor);
}

void Space::removeStaticActor(Actor* actor) {
	staticActors.remove(actor);
}

void Space::removeLowStaticActor(Actor* actor) {
    lowStaticActors.remove(actor);
}

void Space::updateMovementUp(Actor* dynamicActor, bool flying) {
    int possibleMovement = dynamicActor->vy;
    if (possibleMovement == 0) return;
    for (auto const& staticActor : staticActors)
        checkCollisionUp(dynamicActor, staticActor, &possibleMovement);
    if (!flying) {
        for (auto const& staticActor : lowStaticActors)
            checkCollisionUp(dynamicActor, staticActor, &possibleMovement);
    }
    dynamicActor->y += possibleMovement;
    dynamicActor->vy = possibleMovement;
}

void Space::checkCollisionUp(Actor* dynamicActor, Actor* staticActor, int* possibleMovement) {
    // Dynamic bounds
    int topDynamic = dynamicActor->y - dynamicActor->height / 2;
    int bottomDynamic = dynamicActor->y + dynamicActor->height / 2;
    int leftDynamic = dynamicActor->x - dynamicActor->width / 2;
    int rightDynamic = dynamicActor->x + dynamicActor->width / 2;
    // Static bounds
    int topStatic = staticActor->y - staticActor->height / 2;
    int bottomStatic = staticActor->y + staticActor->height / 2;
    int leftStatic = staticActor->x - staticActor->width / 2;
    int rightStatic = staticActor->x + staticActor->width / 2;
    // Check
    if ((topDynamic + dynamicActor->vy) < bottomStatic
        && bottomDynamic > topStatic
        && leftDynamic < rightStatic
        && rightDynamic > leftStatic) {
        // Collision
        dynamicActor->collisionedWith(staticActor);
        staticActor->collisionedWith(dynamicActor);
        if (*possibleMovement < bottomStatic - topDynamic) {
            *possibleMovement = bottomStatic - topDynamic;
        }
    }
}

void Space::updateMovementLeft(Actor* dynamicActor, bool flying) {
    int possibleMovement = dynamicActor->vx;
    if (possibleMovement == 0) return;
    for (auto const& staticActor : staticActors)
        checkCollisionLeft(dynamicActor, staticActor, &possibleMovement);
    if (!flying) {
        for (auto const& staticActor : lowStaticActors)
            checkCollisionLeft(dynamicActor, staticActor, &possibleMovement);
    }
    dynamicActor->x += possibleMovement;
    dynamicActor->vx = possibleMovement;
}

void Space::checkCollisionLeft(Actor* dynamicActor, Actor* staticActor, int* possibleMovement) {
    // Dynamic bounds
    int leftDynamic = dynamicActor->x - dynamicActor->width / 2;
    int topDynamic = dynamicActor->y - dynamicActor->height / 2;
    int bottomDynamic = dynamicActor->y + dynamicActor->height / 2;
    // Static bounds
    int rightStatic = staticActor->x + staticActor->width / 2;
    int topStatic = staticActor->y - staticActor->height / 2;
    int bottomStatic = staticActor->y + staticActor->height / 2;
    // Check
    if ((leftDynamic + dynamicActor->vx) < rightStatic
        && leftDynamic >= rightStatic
        && topStatic < bottomDynamic
        && bottomStatic > topDynamic) {
        // Collision
        dynamicActor->collisionedWith(staticActor);
        staticActor->collisionedWith(dynamicActor);
        if (*possibleMovement < rightStatic - leftDynamic) {
            *possibleMovement = rightStatic - leftDynamic;
        }
    }
}

void Space::updateMovementRight(Actor* dynamicActor, bool flying) {
    int possibleMovement = dynamicActor->vx;
    for (auto const& staticActor : staticActors)
        checkCollisionRight(dynamicActor, staticActor, &possibleMovement);
    if (!flying) {
        for (auto const& staticActor : lowStaticActors)
            checkCollisionRight(dynamicActor, staticActor, &possibleMovement);
    }
    dynamicActor->x += possibleMovement;
    dynamicActor->vx = possibleMovement;
}

void Space::checkCollisionRight(Actor* dynamicActor, Actor* staticActor, int* possibleMovement) {
    // Dynamic bounds
    int rightDynamic = dynamicActor->x + dynamicActor->width / 2;
    int topDynamic = dynamicActor->y - dynamicActor->height / 2;
    int bottomDynamic = dynamicActor->y + dynamicActor->height / 2;
    // Static bounds
    int leftStatic = staticActor->x - staticActor->width / 2;
    int topStatic = staticActor->y - staticActor->height / 2;
    int bottomStatic = staticActor->y + staticActor->height / 2;
    // Check
    if ((rightDynamic + dynamicActor->vx) > leftStatic
        && rightDynamic <= leftStatic
        && topStatic < bottomDynamic
        && bottomStatic > topDynamic) {
        // Collision
        dynamicActor->collisionedWith(staticActor);
        staticActor->collisionedWith(dynamicActor);
        if (*possibleMovement > leftStatic - rightDynamic) {
            *possibleMovement = leftStatic - rightDynamic;
        }
    }
}

void Space::updateMovementBottom(Actor* dynamicActor, bool flying) {
    int possibleMovement = dynamicActor->vy;
    for (auto const& staticActor : staticActors)
        checkCollisionDown(dynamicActor, staticActor, &possibleMovement);
    if (!flying) {
        for (auto const& staticActor : lowStaticActors)
            checkCollisionDown(dynamicActor, staticActor, &possibleMovement);
    }
    dynamicActor->y += possibleMovement;
    dynamicActor->vy = possibleMovement;
}

void Space::checkCollisionDown(Actor* dynamicActor, Actor* staticActor, int* possibleMovement) {
    // Dynamic bounds
    int topDynamic = dynamicActor->y - dynamicActor->height / 2;
    int bottomDynamic = dynamicActor->y + dynamicActor->height / 2;
    int leftDynamic = dynamicActor->x - dynamicActor->width / 2;
    int rightDynamic = dynamicActor->x + dynamicActor->width / 2;
    // Static bounds
    int topStatic = staticActor->y - staticActor->height / 2;
    int bottomStatic = staticActor->y + staticActor->height / 2;
    int leftStatic = staticActor->x - staticActor->width / 2;
    int rightStatic = staticActor->x + staticActor->width / 2;
    // Check
    if ((bottomDynamic + dynamicActor->vy) > topStatic
        && topDynamic < bottomStatic
        && leftDynamic < rightStatic
        && rightDynamic > leftStatic) {
        // Collision
        dynamicActor->collisionedWith(staticActor);
        staticActor->collisionedWith(dynamicActor);
        if (*possibleMovement > topStatic - bottomDynamic) {
            *possibleMovement = topStatic - bottomDynamic;
        }
    }

}