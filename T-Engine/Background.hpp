#pragma once
#include "SDL.h"
#include "Event.hpp"
#include "SDL_EventHandlerInterface.hpp"
#include "SDL_EventBus.hpp"

class Background: SDL_EventHandlerInterface {
private:
	SDL_Texture* texture;
	SDL_Rect position;
public:
	Background(SDL_Texture* texture, SDL_Rect position, SDL_EventBus* eventBus) {
		eventBus->subscribe(events::render, this);
		this->texture = texture;
		this->position = position;
	};

	virtual void handleEvent(Event* event, SDL_Renderer* renderer);
};