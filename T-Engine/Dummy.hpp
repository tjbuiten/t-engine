#pragma once
#include "Entity.hpp"

class Dummy : public Entity {
private:
	CollissionManager* collissionManager = nullptr;
	SDL_EventBus* eventBus = nullptr;
public:
	Dummy(SDL_Texture* texture, SDL_Rect position, SDL_EventBus* eventBus, CollissionManager* collissionManager) : Entity(texture, position, eventBus, collissionManager) {
		this->collissionManager = collissionManager;
		this->eventBus = eventBus;
	};

	virtual void handleCollision(ColliderInterface* collider);
	virtual void update();
};