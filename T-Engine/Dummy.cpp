#include "Dummy.hpp"

bool Dummy::collides(ColliderInterface* collider) {
	return (collider->hitbox->x > this->position.x && collider->hitbox->x < this->position.x + 50);
}

void Dummy::handleCollision() {
	this->collissionManager->removeCollider();
	delete this;
}