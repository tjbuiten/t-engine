#include <SDL_image.h>
#include "Events.hpp"
#pragma once

class Event {
private:
public:
	Event(int eventType, SDL_Event* sdl_event = nullptr, int moveSpeed = NULL) {
		this->eventType = eventType;
		this->sdl_event = sdl_event;
		this->moveSpeed = moveSpeed;
	}

	SDL_Event* sdl_event = nullptr;
	int eventType = NULL;
	int moveSpeed = NULL;
};