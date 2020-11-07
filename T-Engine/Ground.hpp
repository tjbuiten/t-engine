#pragma once
#include "Entity.hpp"

class Ground : public Entity {
private:
	CollissionManager* collissionManager = nullptr;
	SDL_EventBus* eventBus = nullptr;
public:
	Ground(SDL_Texture* texture, SDL_Rect position, SDL_EventBus* eventBus, CollissionManager* collissionManager) : Entity(texture, position, eventBus, collissionManager) {
		this->collissionManager = collissionManager;
		this->eventBus = eventBus;
		this->tagg = taggs::ground;
		this->hitbox.h = 128;
		this->hitbox.w = this->position.w;
		this->hitbox.x = this->position.x;
		this->hitbox.y = this->position.y + 200;
	};
};