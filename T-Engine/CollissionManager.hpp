#pragma once
#include <vector>
#include "ColliderInterface.hpp"

class CollissionManager {
private:
	std::vector<ColliderInterface*> colliders;
public:
	void addCollider(ColliderInterface* collider);
	void removeCollider(ColliderInterface* collider);
	void checkCollissions(ColliderInterface* colliderOne);
	ColliderInterface* getFirstCollission(ColliderInterface* colliderOne, taggs tag);
};