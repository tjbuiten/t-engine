#include "Dummy.hpp"

void Dummy::update() {
	this->hitbox.x = this->position.x;
	this->hitbox.y = this->position.y;
	this->hitbox.w = this->position.w;
	this->hitbox.h = this->position.h;
}

void Dummy::handleCollision(ColliderInterface* collider) {
	this->collissionManager->removeCollider(this);
	this->eventBus->unsubscribe(events::update, this);
	this->eventBus->unsubscribe(events::render, this);
	delete this;
}