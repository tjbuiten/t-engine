#pragma once
#include "Entity.hpp"
#include "Collider.hpp"
#include "InputManager.hpp"

class Player : public Entity {
private:
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
	SDL_Rect source;
	virtual void update();
	virtual void render(SDL_Renderer* renderer);
	virtual bool collisionCheck(Entity* entity);
};
