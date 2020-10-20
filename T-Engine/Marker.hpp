#pragma once
#include "Entity.hpp"

class Marker : public Entity {
private:
	SDL_Rect source;
	int frames = 0;
public:
	bool active = false;
	int direction = 0;
	virtual void update();
	virtual void render(SDL_Renderer* renderer);
};
