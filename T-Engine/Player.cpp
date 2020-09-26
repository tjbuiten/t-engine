#include "Player.hpp"
#include <iostream>

Player::Player() {}

Player::~Player() {}

void Player::Update() {
	int x = 1;
	InputManager inputManager;
	inputManager.Update();

	if (inputManager.KeyDown(SDL_SCANCODE_W)) {
		destination.y--;
	}
	if (inputManager.KeyDown(SDL_SCANCODE_D)) {
		destination.x++;
	}

	if (inputManager.KeyDown(SDL_SCANCODE_S)) {
		destination.y++;
	}
	if (inputManager.KeyDown(SDL_SCANCODE_A)) {
		destination.x--;
	}
}