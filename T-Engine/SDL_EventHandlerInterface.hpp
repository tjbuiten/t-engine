#pragma once
#include "SDL.h"

class SDL_EventHandlerInterface {
private:
public:
	virtual void handleEvent(int eventType);
};