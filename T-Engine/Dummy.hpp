#pragma once
#include "Entity.hpp"
#include "ColliderInterface.hpp"
#include "CollissionManager.hpp"

class Dummy : public Entity, ColliderInterface {
private:
	CollissionManager* collissionManager = nullptr;
public:
	Dummy(SDL_Texture* texture, SDL_Rect position, SDL_EventBus* eventBus, CollissionManager* collissionManager) : Entity(texture, position, eventBus) {
		this->collissionManager = collissionManager;
		collissionManager->addCollider();
	};

	virtual bool collides(ColliderInterface* collider);
	virtual void handleCollision();
};