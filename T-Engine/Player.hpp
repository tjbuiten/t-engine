#pragma once
#include "Entity.hpp"
#include "Marker.hpp"
#include "ColliderInterface.hpp"
#include "CollissionManager.hpp"

class Player : public Entity, ColliderInterface {
private:
	Marker* marker = nullptr;
	CollissionManager* collissionManager = nullptr;
	int direction = 0;
	int lastDirection = 0;
	int velocityY = 0;

	bool shouldSpriteFlip();
public:
	Player(SDL_Texture* texture, SDL_Rect position, SDL_EventBus* eventBus, Marker* marker, CollissionManager* collissionManager): Entity (texture, position, eventBus) {
		this->collissionManager = collissionManager;
		collissionManager->addCollider();

		eventBus->subscribe(SDL_CONTROLLERBUTTONDOWN, this);
		eventBus->subscribe(SDL_CONTROLLERBUTTONUP, this);
		eventBus->subscribe(SDL_JOYAXISMOTION, this);

		this->marker = marker;
	};

	virtual void handleEvent(int eventType, SDL_Renderer* renderer, SDL_Event* event = nullptr);
	virtual void update();
	virtual void render(SDL_Renderer* renderer);
	void handleButtonInput(SDL_Event* event);
	void handleButtonRelease(SDL_Event* event);
	void handleJoystickInput(SDL_Event* event);


	virtual bool collides(ColliderInterface* collider);
	virtual void handleCollision();
};