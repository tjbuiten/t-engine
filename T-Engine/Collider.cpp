#include "Collider.hpp"
#include <iostream>

bool Collider::collisionCheck(Collider* collider) {
	return (
		this->isCollidingHorizontally(collider) &&
		this->isCollidingVertically(collider)
		);
};

bool Collider::isCollidingHorizontally(Collider* collider) {
	return (
		this->collider.x < collider->collider.x &&
		this->collider.x + this->collider.w > collider->collider.x
		) ||
		(
			this->collider.x > collider->collider.x &&
			this->collider.x < collider->collider.x + collider->collider.w
			) || 
		(
			this->collider.x < collider->collider.x + collider->collider.w &&
			this->collider.x + this->collider.w > collider->collider.x + collider->collider.w
			) ||
		(
			this->collider.x + this->collider.w > collider->collider.x &&
			this->collider.x + this->collider.w < collider->collider.x + collider->collider.w
			);
}

bool Collider::isCollidingVertically(Collider* collider) {
	return (
		this->collider.y <= collider->collider.y &&
		this->collider.y + this->collider.h >= collider->collider.y
		) || (
			collider->collider.y <= this->collider.y &&
			collider->collider.y + collider->collider.h >= this->collider.y
			);
}