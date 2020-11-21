#include "TextDisplay.h"

TextDisplay::TextDisplay(Game* game)
{
	TTF_Init();
	this->frontText = new Text("TEXT", WIDTH / 2, 3 * HEIGHT / 4, game);
	this->timer = 0;
}

TextDisplay::~TextDisplay() 
{
	delete frontText;
}

void TextDisplay::draw() 
{
	//timer = 20;						// Debug
	timer--;
	if (timer > 0) {
		frontText->draw();
	}
}

void TextDisplay::update(string content)
{
	frontText->content = content;
	timer = TEXT_DURATION;
}