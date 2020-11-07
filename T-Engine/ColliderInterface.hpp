#pragma once
#include "SDL.h"
#include "Taggs.hpp"

class ColliderInterface {
private:
public:
	taggs tagg = taggs::standard;
	SDL_Rect hitbox;
	virtual bool collides(SDL_Rect* hitbox) = 0;
	virtual void handleCollision(ColliderInterface* collider) = 0;
};