#include "Space.h"

Space::Space() {
	dynamicActors.clear();
	staticActors.clear();
}

void Space::update() {
	for (auto const& actor : dynamicActors) {
		(actor->vx > 0) ? updateMovementRight(actor) : updateMovementLeft(actor);
		(actor->vy > 0) ? updateMovementBottom(actor) : updateMovementUp(actor);
	}
}

void Space::addDynamicActor(Actor* actor) {
	dynamicActors.push_back(actor);
}

void Space::addStaticActor(Actor* actor) {
	staticActors.push_back(actor);
}

void Space::removeDynamicActor(Actor* actor) {
	dynamicActors.remove(actor);
}

void Space::removeStaticActor(Actor* actor) {
	staticActors.remove(actor);
}

void Space::updateMovementUp(Actor* dynamicActor) {
    int possibleMovement = dynamicActor->vy;
    if (possibleMovement == 0) return;
    for (auto const& staticAct : staticActors) {
        // Dynamic bounds
        int topDynamic = dynamicActor->y - dynamicActor->height / 2;
        int bottomDynamic = dynamicActor->y + dynamicActor->height / 2;
        int leftDynamic = dynamicActor->x - dynamicActor->width / 2;
        int rightDynamic = dynamicActor->x + dynamicActor->width / 2;
        // Static bounds
        int topStatic = staticAct->y - staticAct->height / 2;
        int bottomStatic = staticAct->y + staticAct->height / 2;
        int leftStatic = staticAct->x - staticAct->width / 2;
        int rightStatic = staticAct->x + staticAct->width / 2;
        // Collision
        if ((topDynamic + dynamicActor->vy) < bottomStatic
            && bottomDynamic > topStatic
            && leftDynamic < rightStatic
            && rightDynamic > leftStatic) {
            if (possibleMovement < bottomStatic - topDynamic) {
                // Avaliable movement
                possibleMovement = bottomStatic - topDynamic;
            }
        }
    }
    // Ya se han comprobado todos los estáticos
    dynamicActor->y += possibleMovement;
}

void Space::updateMovementLeft(Actor* dynamicActor) {
    int possibleMovement = dynamicActor->vx;
    if (possibleMovement == 0) return;
    for (auto const& staticAct : staticActors) {
        // Dynamic bounds
        int leftDynamic = dynamicActor->x - dynamicActor->width / 2;
        int topDynamic = dynamicActor->y - dynamicActor->height / 2;
        int bottomDynamic = dynamicActor->y + dynamicActor->height / 2;
        // Static bounds
        int rightStatic = staticAct->x + staticAct->width / 2;
        int topStatic = staticAct->y - staticAct->height / 2;
        int bottomStatic = staticAct->y + staticAct->height / 2;
        // Collision
        if ((leftDynamic + dynamicActor->vx) < rightStatic
            && leftDynamic >= rightStatic
            && topStatic < bottomDynamic
            && bottomStatic > topDynamic) {
            if (possibleMovement < rightStatic - leftDynamic) {
                // Avaliable movement
                possibleMovement = rightStatic - leftDynamic;
            }
        }
    }
    dynamicActor->x += possibleMovement;
}

void Space::updateMovementRight(Actor* dynamicActor) {
    int possibleMovement = dynamicActor->vx;
    for (auto const& staticAct : staticActors) {
        // Dynamic bounds
        int rightDynamic = dynamicActor->x + dynamicActor->width / 2;
        int topDynamic = dynamicActor->y - dynamicActor->height / 2;
        int bottomDynamic = dynamicActor->y + dynamicActor->height / 2;
        // Static bounds
        int leftStatic = staticAct->x - staticAct->width / 2;
        int topStatic = staticAct->y - staticAct->height / 2;
        int bottomStatic = staticAct->y + staticAct->height / 2;
        // Collision
        if ((rightDynamic + dynamicActor->vx) > leftStatic
            && rightDynamic <= leftStatic
            && topStatic < bottomDynamic
            && bottomStatic > topDynamic) {
            if (possibleMovement > leftStatic - rightDynamic) {
                // Avaliable movement
                possibleMovement = leftStatic - rightDynamic;
            }
        }
    }
    dynamicActor->x += possibleMovement;

}

void Space::updateMovementBottom(Actor* dynamicActor) {
    int possibleMovement = dynamicActor->vy;
    for (auto const& staticAct : staticActors) {
        // Dynamic bounds
        int topDynamic = dynamicActor->y - dynamicActor->height / 2;
        int bottomDynamic = dynamicActor->y + dynamicActor->height / 2;
        int leftDynamic = dynamicActor->x - dynamicActor->width / 2;
        int rightDynamic = dynamicActor->x + dynamicActor->width / 2;
        // Static bounds
        int topStatic = staticAct->y - staticAct->height / 2;
        int bottomStatic = staticAct->y + staticAct->height / 2;
        int leftStatic = staticAct->x - staticAct->width / 2;
        int rightStatic = staticAct->x + staticAct->width / 2;
        // Collision
        if ((bottomDynamic + dynamicActor->vy) > topStatic
            && topDynamic < bottomStatic
            && leftDynamic < rightStatic
            && rightDynamic > leftStatic) {
            if (possibleMovement > topStatic - bottomDynamic) {
                // Avaliable movement
                possibleMovement = topStatic - bottomDynamic;
            }
        }
    }
    // Ya se han comprobado todos los estáticos
    dynamicActor->y += possibleMovement;

}