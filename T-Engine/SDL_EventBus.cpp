#include "SDL_EventBus.hpp"

void SDL_EventBus::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	for (SDL_EventHandlerInterface* eventHandler : this->eventHandlers.find(event.type)->second)
		eventHandler->handleEvent(event.type);
}

void SDL_EventBus::subscribe(SDL_EventType eventType, SDL_EventHandlerInterface* eventHandler) {
	this->eventHandlers[eventType].push_back(eventHandler);
}