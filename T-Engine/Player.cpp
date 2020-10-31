#include "Player.hpp"

void Player::handleEvent(int eventType, SDL_Renderer* renderer, SDL_Event* event) {
	Entity::handleEvent(eventType, renderer, event);

	switch (eventType) {
	case SDL_CONTROLLERBUTTONDOWN:
		this->handleButtonInput(event);
		break;
	case  SDL_CONTROLLERBUTTONUP:
		this->handleButtonRelease(event);
		break;
	case SDL_JOYAXISMOTION:
		this->handleJoystickInput(event);
		break;
	}
}

void Player::handleButtonInput(SDL_Event* event) {
	switch (event->jbutton.button) {
	case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
		marker->position.x = this->position.x;
		marker->position.y = this->position.y + 16;
		marker->display();
		break;
	case SDL_CONTROLLER_BUTTON_A:
		if (this->position.y == 500)
			this->velocityY = 20;
		break;
	}
}

void Player::handleButtonRelease(SDL_Event* event) {
	switch (event->jbutton.button) {
	case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
		if (!marker->isVisible())
			return;

		this->position.x = marker->position.x;
		this->position.y = marker->position.y - 16;
		this->velocityY = 0;
		marker->hide();
		break;
	}
}

void Player::handleJoystickInput(SDL_Event* event) {
	if (event->caxis.axis != SDL_CONTROLLER_AXIS_LEFTX)
		return;

	if (this->direction != 0)
		this->lastDirection = this->direction;

	this->direction = 0;

	if (event->caxis.value < -10000)
		this->direction = -1;
	if (event->caxis.value > 10000)
		this->direction = +1;
};

void Player::update() {
	if (this->marker->isVisible()) {
		if (this->marker->position.x > this->position.x)
			lastDirection = 1;

		if (this->marker->position.x < this->position.x)
			lastDirection = -1;

		return;
	}

	if (this->direction != 0)
		this->position.x = (this->direction < 0) ? this->position.x - 4 : this->position.x + 4;

	this->position.y -= this->velocityY;

	if (this->position.y > 500) {
		this->position.y = 500;
		this->velocityY = 0;
	}

	this->velocityY -= 1;
}


void Player::render(SDL_Renderer* renderer) {
	SDL_RenderCopyEx(
		renderer,
		this->texture,
		NULL,
		&this->position,
		NULL,
		NULL,
		(this->shouldSpriteFlip()) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL
	);
}

bool Player::shouldSpriteFlip() {
	if (!this->marker->isVisible())
		return (this->direction == 0) ? this->lastDirection == 1 : this->direction == 1;

	return (this->marker->position.x == this->position.x) ? this->lastDirection == 1 : this->marker->position.x > this->position.x;
}

bool Player::collides(ColliderInterface* collider) {
	return (collider->hitbox->x > this->position.x && collider->hitbox->x < this->position.x + 50);
}

void Player::handleCollision() {
	this->velocityY += 10;
}