#pragma once
#include "SDL_image.h"
#include "SDL_EventHandlerInterface.hpp"
#include "SDL_EventBus.hpp"
#include "Event.hpp"
#include <iostream>
#include "ColliderInterface.hpp"
#include "CollissionManager.hpp"

class Entity : public SDL_EventHandlerInterface, public ColliderInterface {
public:
	SDL_Texture* texture;
	SDL_Rect position;

	Entity(SDL_Texture* texture, SDL_Rect position, SDL_EventBus* eventBus, CollissionManager* collissionManager) {
		this->texture = texture;
		this->position = position;

		eventBus->subscribe(events::update, this);
		eventBus->subscribe(events::render, this);
		eventBus->subscribe(events::moveLeft, this);
		eventBus->subscribe(events::moveRight, this);

		collissionManager->addCollider(this);
	}

	virtual void handleEvent(Event* event, SDL_Renderer* renderer);
	virtual void update();
	virtual void render(SDL_Renderer* renderer);

	virtual bool collides(SDL_Rect* hitbox);
	virtual void handleCollision(ColliderInterface* collider);
};