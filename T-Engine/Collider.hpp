#pragma once
#include "SDL_image.h"

class Collider {
public:
	Collider() {};
	virtual ~Collider() {};
	SDL_Rect collider;
	virtual bool collisionCheck(Collider* collider);
	bool isCollidingHorizontally(Collider* collider);
	bool isCollidingVertically(Collider* collider);
};