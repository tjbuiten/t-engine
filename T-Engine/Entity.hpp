#pragma once
#include "SDL_image.h"
#include "Collider.hpp"

class Entity: public Collider {
public:
	Entity() {};
	virtual ~Entity() {};
	SDL_Rect destination;
	SDL_Texture* texture;
	virtual void update();
	virtual void render(SDL_Renderer* renderer);
};