#include "CollissionManager.hpp"
#include <iostream>

void CollissionManager::addCollider(ColliderInterface* collider) {
	this->colliders.push_back(collider);
}

void CollissionManager::checkCollissions(ColliderInterface* colliderOne) {
	for (ColliderInterface* colliderTwo : this->colliders) {
		if (colliderOne != colliderTwo) {
			if (colliderOne->collides(&colliderTwo->hitbox)) {
				colliderOne->handleCollision(colliderTwo);
				colliderTwo->handleCollision(colliderOne);
			}
		}
	}
}

void CollissionManager::removeCollider(ColliderInterface* collider) {
	auto it = std::find(this->colliders.begin(), this->colliders.end(), collider);

	if (it != this->colliders.end())
		this->colliders.erase(it);
}

ColliderInterface* CollissionManager::getFirstCollission(ColliderInterface* colliderOne, taggs tag = taggs::standard) {
	int closestColliderDistance = 9999;
	ColliderInterface* closestCollider = nullptr;

	for (ColliderInterface* colliderTwo : this->colliders) {
		if (colliderOne != colliderTwo && colliderTwo->isTypeOf(tag) && colliderOne->collides(&colliderTwo->hitbox)) {
			int distanceLeft = (abs(colliderOne->hitbox.x - colliderTwo->hitbox.x) < abs(colliderOne->hitbox.x - (colliderTwo->hitbox.x + colliderTwo->hitbox.w))) ?
				abs(colliderOne->hitbox.x - colliderTwo->hitbox.x) : abs(colliderOne->hitbox.x - (colliderTwo->hitbox.x + colliderTwo->hitbox.w));
			int distanceRight = (abs((colliderOne->hitbox.x + colliderOne->hitbox.w) - colliderTwo->hitbox.x) < abs((colliderOne->hitbox.x + colliderOne->hitbox.w) - (colliderTwo->hitbox.x + colliderTwo->hitbox.w))) ?
				abs((colliderOne->hitbox.x + colliderOne->hitbox.w) - colliderTwo->hitbox.x) : abs((colliderOne->hitbox.x + colliderOne->hitbox.w) - (colliderTwo->hitbox.x + colliderTwo->hitbox.w));

			int distanceX = (distanceLeft < distanceRight) ? distanceLeft : distanceRight;
			
			int colliderDistance = abs(distanceX) + abs(colliderOne->hitbox.y - colliderTwo->hitbox.y);

			if (colliderDistance < closestColliderDistance) {
				closestColliderDistance = colliderDistance;
				closestCollider = colliderTwo;
			}
		}
	}

	return closestCollider;
};