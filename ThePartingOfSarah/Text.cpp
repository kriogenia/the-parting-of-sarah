#include "Text.h"

Text::Text(string content, float x, float y, bool title, Game* game) :
	content(content),
	x(x),
	y(y),
	game(game)
{
	if (title) {
		outlineSize = TITLE_OUTLINE_SIZE;
		bgFont = game->fontOutlineTitle;
		fgFont = game->fontTitle;
	}
	else {
		outlineSize = SUBTITLE_OUTLINE_SIZE;
		bgFont = game->fontOutlineSubtitle;
		fgFont = game->fontSubtitle;
	}
}

void Text::draw() {
	SDL_Color white = { 0xFF, 0xFF, 0xFF };
	SDL_Color black = { 0x00, 0x00, 0x00 };
	/* Render outline text */
	SDL_Surface* bg_surface = TTF_RenderText_Blended(bgFont, content.c_str(), black);
	SDL_Texture* bg_texture = SDL_CreateTextureFromSurface(game->renderer, bg_surface);
	SDL_Rect bg_rect = { x - bg_surface->w / 2 - outlineSize / 2, y - bg_surface->h / 2 - outlineSize / 2, bg_surface->w, bg_surface->h };
	SDL_FreeSurface(bg_surface);
	SDL_RenderCopy(game->renderer, bg_texture, NULL, &bg_rect);
	SDL_DestroyTexture(bg_texture);
	/* Render foreground text */
	SDL_Surface* fg_surface = TTF_RenderText_Blended(fgFont, content.c_str(), white);
	SDL_Texture* fg_texture = SDL_CreateTextureFromSurface(game->renderer, fg_surface);
	SDL_Rect fg_rect = { x - fg_surface->w / 2, y - fg_surface->h / 2, fg_surface->w, fg_surface->h };
	SDL_FreeSurface(fg_surface);
	SDL_RenderCopy(game->renderer, fg_texture, NULL, &fg_rect);
	SDL_DestroyTexture(fg_texture);
}