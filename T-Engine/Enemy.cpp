#include "Enemy.hpp"
#include <iostream>

void Enemy::update() {
	this->velocityX = 0;

	if (this->isPlayerInRange() &&
		!this->attacking)
		this->attacking = true;

	if (!this->attacking)
		this->velocityX = (player->destination.x < this->destination.x) ? -2 : 2;

	if (this->velocityX > 0)
		this->direction = 1;
	if (this->velocityX < 0)
		this->direction = -1;

	this->velocityY--;
	this->destination.y += this->velocityY * -1;
	//this->destination.x += this->velocityX;

	if (this->destination.y >= 640 - this->destination.h) {
		this->velocityY = 0;
		this->destination.y = 640 - this->destination.h;
	}

	this->collider.x = (this->direction > 0) ? this->destination.x : this->destination.x + 45;
	this->collider.y = this->destination.y;
	this->collider.h = this->destination.h;
	this->collider.w = 45 * direction;
}

void Enemy::render(SDL_Renderer * renderer) {
	source.h = 111;
	source.w = 111;

	if (attacking) {
		if (frames == 50) {
			source.x += 111;

			if (source.x > 888) {
				source.x = 0;
				this->attacking = false;
			}

			frames = 0;
		}
		else {
			frames++;
		}
	}

	source.y = 0;

	SDL_RenderCopyEx(
		renderer,
		texture,
		&source,
		&destination,
		NULL,
		NULL,
		(this->direction == 1) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL
	);
};

bool Enemy::isPlayerInRange() {
	return
		(this->destination.x > player->destination.x && (this->destination.x - player->destination.x) < 40) ||
		(this->destination.x < player->destination.x && (player->destination.x - this->destination.x) < 40);
}