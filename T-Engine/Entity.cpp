#include "Entity.hpp"
#include <iostream>

void Entity::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(
		renderer,
		texture,
		NULL,
		&destination
	);
};

void Entity::update() {

}