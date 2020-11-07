#include "Marker.hpp"

void Marker::update() {
	if (!visible)
		return;

	if (this->verticalDirection != 0)
		this->position.y = (this->verticalDirection < 0) ? this->position.y - 4 : this->position.y + 4;

	if (this->horizontalDirection != 0)
		this->position.x = (this->horizontalDirection < 0) ? this->position.x - 4 : this->position.x + 4;
}

void Marker::render(SDL_Renderer* renderer) {
	if (!visible)
		return;

	SDL_RenderCopy(renderer, this->texture, &this->textureOrigin, &this->position);

	this->frames++;

	if (frames >= 3) {
		this->textureOrigin.x += this->position.w;

		if (this->textureOrigin.x > 704) {
			this->textureOrigin.x = 0;
		}

		this->frames = 0;
	}
}

void Marker::display() {
	this->visible = true;
}

void Marker::hide() {
	this->visible = false;
}

bool Marker::isVisible() {
	return this->visible;
}

void Marker::handleEvent(Event* event, SDL_Renderer* renderer) {
	Entity::handleEvent(event, renderer);

	switch (event->eventType) {
	case SDL_JOYAXISMOTION:
		this->handleJoystickInput(event->sdl_event);
		break;
	}
}

void Marker::handleJoystickInput(SDL_Event* event) {
	if (event->caxis.axis == SDL_CONTROLLER_AXIS_LEFTY) {
		this->verticalDirection = 0;

		if (event->caxis.value < -10000)
			this->verticalDirection = -1;
		if (event->caxis.value > 10000)
			this->verticalDirection = 1;
	}

	if (event->caxis.axis == SDL_CONTROLLER_AXIS_LEFTX) {
		this->horizontalDirection = 0;

		if (event->caxis.value < -10000)
			this->horizontalDirection = -1;
		if (event->caxis.value > 10000)
			this->horizontalDirection = 1;
	}
};