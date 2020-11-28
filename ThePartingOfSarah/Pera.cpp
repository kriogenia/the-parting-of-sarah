#include "Pera.h"

Pera::Pera(float x, float y, Environment* room, Game* game) :
	Boss("res/sprites/pera/Pera_Moving.png", x, y, 44, 64, room, game)
{
	importAnimations();

	this->name = "Pera";
	this->subtitle = "A.K.A. Kiko Matamoros";
	this->cooldown = DEFAULT_BOSS_CD;

	this->maxHp = PERA_HP;
	this->hp = maxHp;
	this->speed = PERA_SPEED;
	this->flying = true;

	this->animation = movingAnimations[LEFT];
}

Pera::~Pera()
{
	delete reflectAnimation;
	delete sprintAnimation;
	delete throwMinesAnimation;
}

void Pera::importAnimations()
{
	dyingAnimation = new Animation("res/sprites/pera/Pera_Dying.png",
		width, height, 176, 64, 4, 4, false, game);
	movingAnimations.clear();
	movingAnimations.insert_or_assign(LEFT, new Animation("res/sprites/pera/Pera_Moving.png",
		width, height, 176, 64, 4, 4, true, game));
	reflectAnimation = new Animation("res/sprites/pera/Pera_Reflecting.png",
		width, height, 176, 64, 4, 4, false, game);
	sprintAnimation = new Animation("res/sprites/pera/Pera_Running.png",
		width, height, 176, 64, 4, 4, false, game);
	throwMinesAnimation = new Animation("res/sprites/pera/Pera_Throwing.png",
		width, height, 176, 64, 4, 4, false, game);
}

void Pera::doAction()
{
	int actionIndex = rand() % DEFAULT_BOSS_ACTIONS;
	switch (actionIndex) {
	case REFLECT:
		reflect();
		break;
	case SPRINT:
		sprint();
		break;
	case THROW_MINES:
		throwMines();
		break;
	}
}

void Pera::reflect()
{

}

void Pera::sprint()
{

}

void Pera::throwMines()
{

}