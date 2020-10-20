#include "Marker.hpp"

void Marker::update() {
	if (active)
		this->destination.x += this->direction * 10;
}

void Marker::render(SDL_Renderer* renderer) {
	if (active) {
		this->destination.h = 32;
		this->destination.w = 32;

		this->source.h = 32;
		this->source.w = 32;
		this->source.y = 0;

		frames++;

		if (frames == 5) {
			source.x = (source.x == 352) ? 0 : source.x + 32;
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