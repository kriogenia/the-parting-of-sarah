#include "Stone.h"

Stone::Stone(float x, float y, Environment* room, Game* game) :
	Enemy("res/sprites/rock/Rock_Large_Moving_Left.png", x, y, 38, 34, room, game)
{
	importAnimations();

	this->points = ROCK_LARGE_POINTS;
	this->hp = ROCK_LARGE_HP;
	this->speed = ROCK_LARGE_SPEED;

	this->animation = movingAnimations[LEFT];
}

void Stone::importAnimations()
{
	dyingAnimation = new Animation("res/sprites/rock/Rock_Large_Dying.png",
		width, height, 38, 34, 2, 1, false, game);
	hitAnimations.clear();
	hitAnimations.insert_or_assign(LEFT, new Animation("res/sprites/rock/Rock_Large_Hit_Left.png",
		width, height, 38, 34, 4, 1, false, game));
	hitAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/rock/Rock_Large_Hit_Right.png",
		width, height, 38, 34, 4, 1, false, game));
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/rock/Rock_Large_Moving_Left.png",
		width, height, 532, 34, 4, 14, true, game));
	movingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/rock/Rock_Large_Moving_Right.png",
		width, height, 532, 34, 4, 14, true, game));
}

void Stone::death()
{
	this->action = DYING;
	this->animation = dyingAnimation;
	for (auto const& observer : observers) {
		observer->notify(NOTIFICATION_ENEMY_KILLED, this);
	}
	room->addEnemy(new MediumStone(x + 5, y, room, game));
	room->addEnemy(new MediumStone(x - 5, y, room, game));
}

/* Medium Stone */

Stone::MediumStone::MediumStone(float x, float y, Environment* room, Game* game) :
	Enemy("res/sprites/rock/Rock_Medium_Moving_Left.png", x, y, 32, 28, room, game)
{
	importAnimations();

	this->points = ROCK_MEDIUM_POINTS;
	this->hp = ROCK_MEDIUM_HP;
	this->speed = ROCK_MEDIUM_SPEED;

	this->animation = movingAnimations[LEFT];
}

void Stone::MediumStone::importAnimations()
{
	dyingAnimation = new Animation("res/sprites/rock/Rock_Medium_Dying.png",
		width, height, 32, 28, 2, 1, false, game);
	hitAnimations.clear();
	hitAnimations.insert_or_assign(LEFT, new Animation("res/sprites/rock/Rock_Medium_Hit_Left.png",
		width, height, 32, 28, 4, 1, false, game));
	hitAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/rock/Rock_Medium_Hit_Right.png",
		width, height, 32, 28, 4, 1, false, game));
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/rock/Rock_Medium_Moving_Left.png",
		width, height, 416, 28, 4, 13, true, game));
	movingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/rock/Rock_Medium_Moving_Right.png",
		width, height, 416, 28, 4, 13, true, game));
}

void Stone::MediumStone::death()
{
	this->action = DYING;
	this->animation = dyingAnimation;
	for (auto const& observer : observers) {
		observer->notify(NOTIFICATION_ENEMY_KILLED, this);
	}
	room->addEnemy(new SmallStone(x + 5, y, room, game));
	room->addEnemy(new SmallStone(x - 5, y, room, game));
}

/* Small Stone */

Stone::SmallStone::SmallStone(float x, float y, Environment* room, Game* game) :
	Enemy("res/sprites/rock/Rock_Small_Moving_Left.png", x, y, 22, 18, room, game)
{
	importAnimations();

	this->points = ROCK_SMALL_POINTS;
	this->hp = ROCK_SMALL_HP;
	this->speed = ROCK_SMALL_SPEED;

	this->animation = movingAnimations[LEFT];
}

void Stone::SmallStone::importAnimations()
{
	dyingAnimation = new Animation("res/sprites/rock/Rock_Small_Dying.png",
		width, height, 110, 18, 2, 5, false, game);
	hitAnimations.clear();
	hitAnimations.insert_or_assign(LEFT, new Animation("res/sprites/rock/Rock_Small_Hit_Left.png",
		width, height, 110, 18, 4, 5, false, game));
	hitAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/rock/Rock_Small_Hit_Right.png",
		width, height, 110, 18, 4, 5, false, game));
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/rock/Rock_Small_Moving_Left.png",
		width, height, 242, 18, 4, 11, true, game));
	movingAnimations.insert_or_assign(RIGHT, new Animation("res/sprites/rock/Rock_Small_Moving_Right.png",
		width, height, 242, 18, 4, 11, true, game));
}

void Stone::SmallStone::death()
{
	this->action = DYING;
	this->animation = dyingAnimation;
	for (auto const& observer : observers) {
		observer->notify(NOTIFICATION_ENEMY_KILLED, this);
	}
	// 1 out 4 chances to drop a coin
	if (rand() % (COIN_RARITY * 4) == 0) {
		room->spawnCoin(x, y);
	}
}