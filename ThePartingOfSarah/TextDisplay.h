#pragma once

#include "Text.h"

constexpr auto TEXT_DURATION = 30;				// 1s

class TextDisplay
{
public:
	TextDisplay(Game* game);
	~TextDisplay();

	void draw();
	void update(string content);

private:
	Game* game;
	Text* frontText;

	int timer;
};

