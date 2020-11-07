#include "Entity.hpp"

void Entity::handleEvent(Event* event, SDL_Renderer* renderer) {
	switch (event->eventType) {
	case events::update:
		this->update();
		break;
	case events::render:
		this->render(renderer);
		break;
	case events::moveLeft:
		this->position.x -= 4;
		this->hitbox.x -= 4;
		break;
	case events::moveRight:
		this->position.x += 4;
		this->hitbox.x += 4;
		break;
	}
}

void Entity::update() {};

void Entity::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, this->texture, NULL, &this->position);
}

bool Entity::collides(SDL_Rect* hitbox) {
	return ((this->hitbox.x > hitbox->x && this->hitbox.x < hitbox->x + hitbox->w) ||
			(hitbox->x > this->hitbox.x && hitbox->x < this->hitbox.x + this->hitbox.w));
}

void Entity::handleCollision(ColliderInterface* collider) {

}