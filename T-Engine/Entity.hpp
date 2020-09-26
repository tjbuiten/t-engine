#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <vector>

class Entity {
public:
	SDL_Renderer* renderer;
	SDL_Rect destination; 
	SDL_Texture* texture;

	Entity();
	~Entity();
	
	virtual void Render();

	virtual void Update();

	void LoadTexture();

	void CheckCollissions(std::vector<Entity*> entities) {
		for (Entity* entity : entities) {
			if (entity == this) {
				continue;
			}

			if (
				((
					entity->destination.x < destination.x &&
					entity->destination.x + entity->destination.w > destination.x
				) ||
				(
					entity->destination.x > destination.x &&
					entity->destination.x < destination.x + destination.w
				)) &&
				((
					entity->destination.y < destination.y &&
					entity->destination.y + entity->destination.h > destination.y
				) ||
				(
					entity->destination.y > destination.y &&
					entity->destination.y < destination.y + destination.h
				))
				) {
				OnCollision(entity);
			};
		}
	};

	void OnCollision(Entity* collidingObject) {

	}
};