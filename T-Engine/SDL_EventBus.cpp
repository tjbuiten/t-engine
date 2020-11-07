#include "SDL_EventBus.hpp"
#include <iostream>

void SDL_EventBus::subscribe(int eventType, SDL_EventHandlerInterface* eventHandler) {
	this->eventHandlers[eventType].push_back(eventHandler);
}

void SDL_EventBus::handleEvent(Event* event) {
	std::map<int, std::vector<SDL_EventHandlerInterface*>>::iterator it = this->eventHandlers.find(event->eventType);

	if (it == this->eventHandlers.end())
		return;

	for (SDL_EventHandlerInterface* eventHandler : it->second)
		eventHandler->handleEvent(event, this->renderer);
}

void SDL_EventBus::unsubscribe(int eventType, SDL_EventHandlerInterface* eventHandler) {
	auto it = std::find(this->eventHandlers[eventType].begin(), this->eventHandlers[eventType].end(), eventHandler);

	if (it != this->eventHandlers[eventType].end())
		this->eventHandlers[eventType].erase(it);
}
