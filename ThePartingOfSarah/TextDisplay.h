#pragma once

#include "Text.h"

constexpr auto TEXT_DURATION = 90;				// 3s

class TextDisplay
{
public:
	TextDisplay(Game* game);
	~TextDisplay();

	void draw();
	void update(string title, string subtitle);

private:
	Text* title;
	Text* subtitle;

	int timer;
};

