#pragma once
#include "SDL.h"
#include <vector>
#include <map>
#include "SDL_EventHandlerInterface.hpp"

class SDL_EventBus {
private:
	std::map<int, std::vector<SDL_EventHandlerInterface*>> eventHandlers;
public:
	void subscribe(int, SDL_EventHandlerInterface*);

	void handleEvent(int eventType, SDL_Renderer* renderer, SDL_Event* event = nullptr);
};