#pragma once
#include "SDL_image.h"

class Entity {
public:
	SDL_Rect destination;
	SDL_Texture* texture;
	virtual void update();
	virtual void render(SDL_Renderer* renderer);
};