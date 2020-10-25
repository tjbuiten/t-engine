#pragma once
#include "SDL.h"
#include "SDL_EventHandlerInterface.hpp"
#include "GameManager.hpp"

class SDL_EventsHandler : public SDL_EventHandlerInterface {
private:
	GameManager* gameManager;
public:
	SDL_EventsHandler(GameManager* gameManager) {
		this->gameManager = gameManager;
	}

	virtual void handleEvent(int eventType);
};