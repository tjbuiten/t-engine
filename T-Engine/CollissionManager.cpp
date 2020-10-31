#include "CollissionManager.hpp"

void CollissionManager::addCollider(ColliderInterface* collider) {
	this->colliders.push_back(collider);
}

void CollissionManager::checkCollissions() {
	for (ColliderInterface* colliderOne : this->colliders) {
		for (ColliderInterface* colliderTwo : this->colliders) {
			if (colliderOne->collides(colliderTwo->hitbox)) {
				colliderOne->handleCollision();
				colliderTwo->handleCollision();
			}
		}
	}
}

void CollissionManager::removeCollider(ColliderInterface* collider) {
	auto it = std::find(this->colliders.begin(), this->colliders.end(), collider);

	if (it != this->colliders.end())
		this->colliders.erase(it);
}