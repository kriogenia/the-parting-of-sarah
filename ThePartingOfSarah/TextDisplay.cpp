#include "TextDisplay.h"

TextDisplay::TextDisplay(Game* game)
{
	this->title = new Text("TITLE", WIDTH / 2, 3 * HEIGHT / 4, true, game);
	this->subtitle = new Text("SUBTITLE", WIDTH / 2, 3 * HEIGHT / 4 + 24, false, game);
	this->timer = 0;
}

TextDisplay::~TextDisplay() 
{
	delete title;
	delete subtitle;
}

void TextDisplay::draw() 
{
	//timer = 20;						// Debug
	if (timer > 0) {
		timer--;
		title->draw();
		subtitle->draw();
	}
}

void TextDisplay::update(string title, string subtitle)
{
	this->title->content = title;
	this->subtitle->content = subtitle;
	timer = TEXT_DURATION;
}