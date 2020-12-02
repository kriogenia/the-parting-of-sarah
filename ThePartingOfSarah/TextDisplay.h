#pragma once

#include "Text.h"

constexpr auto TEXT_DURATION = 90;				// 3s

class TextDisplay
{
public:
	TextDisplay(Game* game);
	~TextDisplay();
	/* Game cycle */
	void draw();
	void update(string title, string subtitle);

private:
	/* Texts */
	Text* title;
	Text* subtitle;
	/* Counter */
	int timer;
};

