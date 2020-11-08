#include "ColliderInterface.hpp"

bool ColliderInterface::isTypeOf(int tagg) {
	return (std::find(this->types.begin(), this->types.end(), tagg) != this->types.end());
}

void ColliderInterface::addTagg(taggs tagg) {
	this->types.push_back(tagg);
}