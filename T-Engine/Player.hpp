#pragma once
#include "Entity.hpp"
#include "Marker.hpp"

class Player : public Entity {
private:
	SDL_EventBus* eventBus = nullptr;
	Marker* marker = nullptr;
	int direction = 0;
	int lastDirection = 0;
	int velocityY = 0;
	int groundHeight = 522;
	CollissionManager* collissionManager;
	bool canDash = false;

	bool shouldSpriteFlip();
public:
	Player(SDL_Texture* texture, SDL_Rect position, SDL_EventBus* eventBus, Marker* marker, CollissionManager* collissionManager): Entity (texture, position, eventBus, collissionManager) {
		this->collissionManager = collissionManager;

		eventBus->subscribe(SDL_CONTROLLERBUTTONDOWN, this);
		eventBus->subscribe(SDL_CONTROLLERBUTTONUP, this);
		eventBus->subscribe(SDL_JOYAXISMOTION, this);

		this->marker = marker;
		this->eventBus = eventBus;

		this->hitbox.x = this->position.x;
		this->hitbox.y = this->position.y;
		this->hitbox.h = this->position.h;
		this->hitbox.w = this->position.w;
	};

	virtual void handleEvent(Event* event, SDL_Renderer* renderer);
	virtual void update();
	virtual void render(SDL_Renderer* renderer);
	void handleButtonInput(SDL_Event* event);
	void handleButtonRelease(SDL_Event* event);
	void handleJoystickInput(SDL_Event* event);
	virtual void handleCollision(ColliderInterface* collider);
};