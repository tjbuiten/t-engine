#pragma once
#include "SDL.h"
#include <vector>
#include <map>
#include "SDL_EventHandlerInterface.hpp"

class SDL_EventBus {
private:
	static SDL_EventBus* instance;

	std::map<SDL_EventType, std::vector<SDL_EventHandlerInterface*>> eventHandlers;

	SDL_EventBus();
public:
	static SDL_EventBus* getInstance() {
		if (instance == NULL)
			instance = new SDL_EventBus;

		return instance;
	}

	void subscribe(SDL_EventType, SDL_EventHandlerInterface*);

	void handleEvents();
};