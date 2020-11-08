#pragma once
#include "Entity.hpp"

class Ground : public Entity {
private:
	CollissionManager* collissionManager = nullptr;
	SDL_EventBus* eventBus = nullptr;
public:
	Ground(SDL_Texture* texture, SDL_Rect position, SDL_EventBus* eventBus, CollissionManager* collissionManager, SDL_Rect hitbox) : Entity(texture, position, eventBus, collissionManager) {
		this->collissionManager = collissionManager;
		this->eventBus = eventBus;
		this->hitbox = hitbox;
	};
};