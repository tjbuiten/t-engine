#include "Marker.hpp"

void Marker::update() {
	if (!active)
		return;

	this->destination.x += this->direction * 10;
}

void Marker::render(SDL_Renderer* renderer) {
	if (active) {
		this->destination.h = 64;
		this->destination.w = 64;

		this->source.h = 64;
		this->source.w = 64;
		this->source.y = 0;

		frames++;

		if (frames == 5) {
			source.x = (source.x == 704) ? 0 : source.x + 64;
			frames = 0;
		}

		SDL_RenderCopyEx(
			renderer,
			texture,
			&source,
			&destination,
			NULL,
			NULL,
			SDL_FLIP_NONE
		);
	}
}