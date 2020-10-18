#pragma once
#include "Entity.hpp"
#include "Collider.hpp"
#include "InputManager.hpp"
#include "Player.hpp"

class Enemy : public Entity {
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
	bool isPlayerInRange();
public:
	Enemy() {};
	~Enemy() {};
	Player* player;
	virtual void update();
	virtual void render(SDL_Renderer* renderer);
};
