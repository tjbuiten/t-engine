#include "Background.hpp"

void Background::handleEvent(Event* event, SDL_Renderer* renderer) {
	if (event->eventType != events::render)
		return;

	SDL_RenderCopy(renderer, this->texture, NULL, &this->position);
}