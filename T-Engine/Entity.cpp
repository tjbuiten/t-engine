#include "Entity.hpp"

void Entity::handleEvent(int eventType, SDL_Renderer* renderer, SDL_Event* event) {
	switch (eventType) {
	case events::update:
		this->update();
		break;
	case events::render:
		this->render(renderer);
		break;
	}
}

void Entity::update() {};

void Entity::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, this->texture, NULL, &this->position);
}

bool Entity::collides(SDL_Rect* hitbox) {
	return false;
}

void Entity::handleCollision() {

}