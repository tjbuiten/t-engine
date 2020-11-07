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
	int closestColliderDistance = INFINITY;
	ColliderInterface* closestCollider = nullptr;

	for (ColliderInterface* colliderTwo : this->colliders) {
		if (colliderOne != colliderTwo && colliderTwo->tagg == tag) {
			int colliderDistance = abs(colliderOne->hitbox.x - colliderTwo->hitbox.x) + abs(colliderOne->hitbox.y - colliderTwo->hitbox.y);
			if (colliderOne->collides(&colliderTwo->hitbox) && (
				closestCollider == nullptr ||
				colliderDistance < closestColliderDistance)) {
				closestColliderDistance = colliderDistance;
				closestCollider = colliderTwo;
			}
		}
	}

	return closestCollider;
};