#pragma once
#include "SDL.h"
#include "Taggs.hpp"
#include <vector>

class ColliderInterface {
private:
	std::vector<taggs> types;
public:
	SDL_Rect hitbox;
	virtual bool collides(SDL_Rect* hitbox) = 0;
	virtual void handleCollision(ColliderInterface* collider) = 0;
	bool isTypeOf(int tag);
	void addTagg(taggs tagg);
};