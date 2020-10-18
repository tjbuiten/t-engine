#include "Player.hpp"
#include <iostream>

void Player::update() {
	if (this->isGrounded()) {
		this->velocityX = 0;

		if (this->inputManager.KeyDown(SDL_SCANCODE_A) &&
			this->destination.x > 0)
			this->velocityX = -5;

		if (this->inputManager.KeyDown(SDL_SCANCODE_D) &&
			this->destination.x < 1280 - destination.w)
			this->velocityX = 5;

		if (this->inputManager.KeyDown(SDL_SCANCODE_SPACE) &&
			!this->dashing &&
			this->destination.x > 10) {
			this->dashing = true;
			this->destination.x += this->direction * -200;
		}

		if (this->inputManager.KeyDown(SDL_SCANCODE_W) && !this->jumping) {
			this->velocityY = 20;
		}
	}
	else {
		if (this->inputManager.KeyDown(SDL_SCANCODE_A) &&
			this->velocityX > -5 &&
			this->destination.x > 0)
			this->velocityX -= 0.5;

		if (this->inputManager.KeyDown(SDL_SCANCODE_D) &&
			this->velocityX < 5 &&
			this->destination.x < 1280 - destination.w)
			this->velocityX += 0.5;

		this->velocityY--;
	}

	if (this->inputManager.MouseClick() &&
		!this->attacking)
		this->attacking = true;


	if (!this->inputManager.KeyDown(SDL_SCANCODE_SPACE))
		this->dashing = false;

	if (!this->inputManager.KeyDown(SDL_SCANCODE_W))
		this->jumping = false;
	else
		this->jumping = true;
 
	if (this->velocityX > 0)
		this->direction = 1;
	if (this->velocityX < 0)
		this->direction = -1;

	this->destination.y += this->velocityY * -1;
	this->destination.x += this->velocityX;

	if (this->destination.y >= 640 - this->destination.h) {
		this->velocityY = 0;
		this->destination.y = 640 - this->destination.h;
	}

	this->collider.x = (this->direction > 0) ? this->destination.x : this->destination.x + 45;
	this->collider.y = this->destination.y;
	this->collider.h = this->destination.h;
	this->collider.w = 45 * direction;

	if (attacking && frames == 1 && source.x >= 555) {
		std::cout << "AYAYAYAYAYYAA\n\n";
		std::cout << "width: " << this->collider.w << "\n\n";
		this->collider.w = 111 * direction;
	}
}

bool Player::isGrounded() {
	return (this->destination.y >= 640 - this->destination.h);
}

void Player::render(SDL_Renderer* renderer) {
	source.h = 111;
	source.w = 111;

	if (attacking) {
		if (frames == 1) {
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
}
bool Player::collisionCheck(Entity* entity)
{
	return false;
}
;