#include "Entity.hpp"

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