#pragma once
#include "SDL_image.h"
#include "SDL_EventHandlerInterface.hpp"
#include "Events.hpp"
#include "SDL_EventBus.hpp"
#include <iostream>

class Entity : public SDL_EventHandlerInterface {
public:
	SDL_Texture* texture;
	SDL_Rect position;

	Entity(SDL_Texture* texture, SDL_Rect position, SDL_EventBus* eventBus) {
		this->texture = texture;
		this->position = position;

		eventBus->subscribe(events::update, this);
		eventBus->subscribe(events::render, this);
	}

	virtual void handleEvent(int eventType, SDL_Renderer* renderer, SDL_Event* event = nullptr);
	virtual void update();
	virtual void render(SDL_Renderer* renderer);
};