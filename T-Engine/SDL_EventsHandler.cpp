#pragma once
#include "SDL_EventsHandler.hpp"

void SDL_EventsHandler::handleEvent(Event* event, SDL_Renderer* renderer) {
	switch (event->eventType) {
	case SDL_QUIT:
		this->gameManager->quitGame();
		break;
	}
}