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
		this->position.x -= event->moveSpeed;
		this->hitbox.x = this->position.x;
		break;
	case events::moveRight:
		this->position.x += event->moveSpeed;
		this->hitbox.x = this->position.x;
		break;
	}
}

void Entity::update() {};

void Entity::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, this->texture, NULL, &this->position);
}

bool Entity::collides(SDL_Rect* hitbox) {
	//std::cout << " thisx: " << this->hitbox.x << " thisy: " << this->hitbox.y << " thisw: " << this->hitbox.w << " thish: " << this->hitbox.h << "\n"
	//	<< " x: " << hitbox->x << " y: " << hitbox->y << " w: " << hitbox->w << " h: " << hitbox->h << "\n"
	//	<< " collides: " << (
	//	((this->hitbox.x > hitbox->x && this->hitbox.x < hitbox->x + hitbox->w) ||
	//		(hitbox->x > this->hitbox.x && hitbox->x < this->hitbox.x + this->hitbox.w)) &&
	//		(
	//		(this->hitbox.y < hitbox->y && this->hitbox.y + this->hitbox.h > hitbox->y) ||
	//			(this->hitbox.y >= hitbox->y && this->hitbox.y + this->hitbox.h <= hitbox->y + hitbox->h) ||
	//			(this->hitbox.y < hitbox->y + hitbox->h && this->hitbox.y + this->hitbox.h >= hitbox->y + hitbox->h)
	//			)
	//		) << " collidesY1: " << (this->hitbox.y < hitbox->y&& this->hitbox.y + this->hitbox.h > hitbox->y)
	//	<< " collidesY2: " << (this->hitbox.y >= hitbox->y && this->hitbox.y + this->hitbox.h <= hitbox->y + hitbox->h)
	//	<< " collidesY3: " << (this->hitbox.y < hitbox->y + hitbox->h && this->hitbox.y + this->hitbox.h >= hitbox->y + hitbox->h) <<
	//	"\n\n";

	return (
		(
			(this->hitbox.x  <= hitbox->x && this->hitbox.x + this->hitbox.w > hitbox->x) ||
			(this->hitbox.x >= hitbox->x && this->hitbox.x + this->hitbox.w <= hitbox->x + hitbox->w) ||
			(this->hitbox.x < hitbox->x + hitbox->w && this->hitbox.x + this->hitbox.w >= hitbox->x + hitbox->w)
		) && (
			(this->hitbox.y <= hitbox->y && this->hitbox.y + this->hitbox.h > hitbox->y) ||
			(this->hitbox.y >= hitbox->y && this->hitbox.y + this->hitbox.h <= hitbox->y + hitbox->h) ||
			(this->hitbox.y < hitbox->y + hitbox->h && this->hitbox.y + this->hitbox.h >= hitbox->y + hitbox->h)
		)
	);
}

void Entity::handleCollision(ColliderInterface* collider) {

}