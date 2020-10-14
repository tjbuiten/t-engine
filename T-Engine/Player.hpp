#pragma once
#include "Entity.hpp"
#include "InputManager.hpp"

class Player : public Entity {
private:
	SDL_Rect source;
	InputManager inputManager;
	float velocityX = 0;
	float velocityY = 0;
	int direction = 1;
	int frames = 0;
	bool jumping = false;
	bool dashing = false;
	bool attacking = false;
	bool isGrounded();
public:
	virtual void update();
	virtual void render(SDL_Renderer* renderer);
};
