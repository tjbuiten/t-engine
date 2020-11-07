#pragma once
#include "SDL.h"
#include "Event.hpp"

class SDL_EventHandlerInterface {
private:
public:
	virtual void handleEvent(Event* event, SDL_Renderer* renderer) = 0;
};