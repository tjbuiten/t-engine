#pragma once
#include "SDL.h"

class ColliderInterface {
private:
public:
	SDL_Rect* hitbox;
	bool collides(ColliderInterface* collider);
	void handleCollision();
};