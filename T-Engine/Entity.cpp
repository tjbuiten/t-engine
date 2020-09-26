#include "Entity.hpp"
#include <iostream>
#include <vector>

Entity::Entity() {}

Entity::~Entity() {}

void Entity::Render() {
	SDL_RenderCopy(renderer, texture, NULL, &destination);
};

void Entity::Update() {};

void Entity::LoadTexture() {};