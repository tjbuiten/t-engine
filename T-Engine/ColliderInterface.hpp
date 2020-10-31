#pragma once
#include "SDL.h"

class ColliderInterface {
private:
public:
	SDL_Rect* hitbox;
	virtual bool collides(SDL_Rect* hitbox) = 0;
	virtual void handleCollision() = 0;
};