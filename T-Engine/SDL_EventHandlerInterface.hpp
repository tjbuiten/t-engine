#pragma once
#include "SDL.h"

class SDL_EventHandlerInterface {
private:
public:
	virtual void handleEvent(int eventType, SDL_Renderer* renderer, SDL_Event* event = nullptr) = 0;
};