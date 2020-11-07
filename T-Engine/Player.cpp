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
		marker->position.x = this->position.x;
		marker->position.y = this->position.y + 16;
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

		this->hitbox.x = this->position.x;
		this->hitbox.y = this->position.y;
		this->hitbox.w = this->marker->position.x - this->position.x;
		this->collissionManager->checkCollissions(this);
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
	this->canMoveLeft = true;
	this->canMoveRight = true;

	int originalH = this->hitbox.h;
	this->hitbox.h = INFINITY;

	ColliderInterface* closestCollider = this->collissionManager->getFirstCollission(this, taggs::ground);
	this->groundHeight = (closestCollider == nullptr) ? 640 : closestCollider->hitbox.y;

	this->hitbox.h = originalH;

	int originalX = this->hitbox.x;
	int originalW = this->hitbox.w;

	this->hitbox.w += 4;

	this->collissionManager->checkCollissions(this);

	this->hitbox.x -= 4;
	this->hitbox.w -= 4;

	this->collissionManager->checkCollissions(this);

	this->hitbox.x = originalX;
	this->hitbox.w = originalW;

	if (this->marker->isVisible()) {
		if (this->marker->position.x > this->position.x)
			lastDirection = 1;

		if (this->marker->position.x < this->position.x)
			lastDirection = -1;

		return;
	}

	if (this->direction != 0) {
		int originalX = this->hitbox.x;
		int originalW = this->hitbox.w;

		this->hitbox.w += 4;

		this->collissionManager->checkCollissions(this);

		this->hitbox.x -= 4;
		this->hitbox.w -= 4;

		this->collissionManager->checkCollissions(this);

		this->hitbox.x = originalX;
		this->hitbox.w = originalW;

		if (this->direction == -1 && this->canMoveLeft)
			//this->eventBus->handleEvent(new Event(events::moveRight, nullptr, 4));
			if (this->direction == 1 && this->canMoveRight)
				std::cout << "\n";
			//this->eventBus->handleEvent(new Event(events::moveLeft, nullptr, 4));
	}

	this->position.y -= this->velocityY;

	if (this->position.y > this->groundHeight - this->position.h) {
		this->position.y = this->groundHeight - this->position.h;
		this->velocityY = 0;
	}

	this->velocityY -= 1;

	this->hitbox.h = this->position.h;
	this->hitbox.w = this->position.w;
	this->hitbox.x = this->position.x;
	this->hitbox.y = this->position.y;
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
	switch (collider->tagg) {
	case (taggs::ground):
		if (this->position.y + this->position.h <= collider->hitbox.y)
			return;
		
		if (this->position.x >= collider->hitbox.x + collider->hitbox.w)
			this->canMoveLeft = false;
		if (this->position.x + this->position.w <= collider->hitbox.x || this->position.x + this->position.w <= collider->hitbox.x + collider->hitbox.w) {
			this->canMoveRight = false;
		}
		return;
	}

	this->groundHeight = 640;
}	