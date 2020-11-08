#include "Player.hpp"

void Player::handleEvent(Event* event, SDL_Renderer* renderer) {
	switch (event->eventType) {
	case events::update:
		this->update();
		break;
	case events::render:
		this->render(renderer);
		break;
	case SDL_CONTROLLERBUTTONDOWN:
		this->handleButtonInput(event->sdl_event);
		break;
	case  SDL_CONTROLLERBUTTONUP:
		this->handleButtonRelease(event->sdl_event);
		break;
	case SDL_JOYAXISMOTION:
		this->handleJoystickInput(event->sdl_event);
		break;
	}
}

void Player::handleButtonInput(SDL_Event* event) {
	switch (event->jbutton.button) {
	case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
		if (!this->canDash)
			return;

		marker->position.x = this->position.x;
		marker->position.y = this->position.y;
		marker->originX = this->position.x;
		marker->originY = this->position.y;
		marker->display();
		break;
	case SDL_CONTROLLER_BUTTON_A:
		if (this->position.y == this->groundHeight - this->position.h)
			this->velocityY = 20;
		break;
	}
}

void Player::handleButtonRelease(SDL_Event* event) {
	switch (event->jbutton.button) {
	case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
		if (!marker->isVisible())
			return;

		(this->position.x < this->marker->position.x) ?
			this->eventBus->handleEvent(new Event(events::moveRight, nullptr, this->position.x - this->marker->position.x)) :
			this->eventBus->handleEvent(new Event(events::moveLeft, nullptr, this->marker->position.x - this->position.x));

		this->position.x = marker->position.x;
		this->position.y = marker->position.y - 16;
		this->velocityY = 0;
		this->canDash = false;
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
	this->hitbox.x = this->position.x;
	this->hitbox.y = this->position.y;
	this->hitbox.w = this->position.w;
	this->hitbox.h = this->position.h;

	if (this->position.y + this->position.h == this->groundHeight)
		this->canDash = true;

	if (this->marker->isVisible()) {
		if (this->marker->position.x > this->position.x)
			lastDirection = 1;

		if (this->marker->position.x < this->position.x)
			lastDirection = -1;

		return;
	}

	if (this->direction == 1) {
		int originalH = this->hitbox.h;
		int originalY = this->hitbox.y;

		this->hitbox.w += 4;
		this->hitbox.y += this->hitbox.h - 10;
		this->hitbox.h = 10;

		ColliderInterface* collider = this->collissionManager->getFirstCollission(this, taggs::wall);

		this->hitbox.w -= 4;
		this->hitbox.y = originalY;
		this->hitbox.h = originalH;

		if (collider == nullptr)
			this->eventBus->handleEvent(new Event(events::moveLeft, nullptr, 4));
	}

	if (this->direction == -1) {
		int originalH = this->hitbox.h;
		int originalY = this->hitbox.y;

		this->hitbox.x -= 4;
		this->hitbox.y += this->hitbox.h - 10;
		this->hitbox.h = 10;

		ColliderInterface* collider = this->collissionManager->getFirstCollission(this, taggs::wall);

		this->hitbox.x += 4;
		this->hitbox.y = originalY;
		this->hitbox.h = originalH;

		if (collider == nullptr)
			this->eventBus->handleEvent(new Event(events::moveRight, nullptr, 4));
	}

	int originalH = this->hitbox.h;
	int originalY = this->hitbox.y;
	this->hitbox.y += this->hitbox.h;
	this->hitbox.h = 9999;

	ColliderInterface* closestCollider = this->collissionManager->getFirstCollission(this, taggs::ground);
	this->groundHeight = (closestCollider == nullptr) ? 640 : closestCollider->hitbox.y;

	this->hitbox.h = originalH;
	this->hitbox.y = originalY;

	this->position.y -= this->velocityY;

	if (this->position.y > this->groundHeight - this->position.h && this->velocityY <= 0) {
		this->position.y = this->groundHeight - this->position.h;
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

void Player::handleCollision(ColliderInterface* collider) {
}	