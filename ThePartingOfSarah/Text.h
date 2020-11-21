#pragma once

#include "Game.h"

constexpr auto TEXT_BLACK = 0;
constexpr auto TEXT_WHITE = 255;

class Text
{
public:
	Text(string content, float x, float y, bool title, Game* game);

	void draw();

	string content;

private:
	int outlineSize;
	int x;
	int y;
	int width;
	int height;

	Game* game;
	TTF_Font* bgFont;
	TTF_Font* fgFont;

};
