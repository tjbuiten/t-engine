#pragma once
#include "SDL_EventsHandler.hpp"

void SDL_EventsHandler::handleEvent(int eventType, SDL_Renderer* renderer, SDL_Event* event) {
	switch (eventType) {
	case SDL_QUIT:
		this->gameManager->quitGame();
		break;
	}
}