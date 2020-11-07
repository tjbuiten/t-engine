#pragma once
#include "SDL.h"
#include <vector>
#include "Event.hpp"
#include <map>
#include "SDL_EventHandlerInterface.hpp"

class SDL_EventBus {
private:
	SDL_Renderer* renderer = nullptr;
	std::map<int, std::vector<SDL_EventHandlerInterface*>> eventHandlers;
public:
	SDL_EventBus(SDL_Renderer* renderer) {
		this->renderer = renderer;
	}

	void subscribe(int, SDL_EventHandlerInterface*);

	void handleEvent(Event* event = nullptr);

	void unsubscribe(int, SDL_EventHandlerInterface*);
};