#include "Texture.hpp"

void Texture::render(SDL_Renderer* renderer, SDL_Rect offset) {
	SDL_Rect* position = new SDL_Rect();
	position->h = this->destination.h;
	position->w = this->destination.w;
	position->x = this->destination.x + offset.x;
	position->y = this->destination.y + offset.y;

	SDL_RenderCopy(renderer, texture, NULL, position);
}