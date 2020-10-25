#include "InputManager.hpp"
#include <iostream>

bool InputManager::KeyDown(SDL_Scancode scanCode) {
	return SDL_GetKeyboardState(NULL)[scanCode];
}

bool InputManager::MovingLeft() {
	return (
		//SDL_JoystickGetAxis(gameController, 0) <= -10000 ||
		this->KeyDown(SDL_SCANCODE_A)
		);
}

bool InputManager::MovingRight() {
	return (
		//SDL_JoystickGetAxis(gameController, 0) >= 10000 ||
		this->KeyDown(SDL_SCANCODE_D)
		);
}

bool InputManager::Jumping() {
	SDL_Event ev;
	SDL_PollEvent(&ev);

	return (
		(int) ev.jbutton.which == 1 ||
		this->KeyDown(SDL_SCANCODE_W)
		);
}

bool InputManager::Crouching() {
	return (
		//SDL_JoystickGetButton(gameController, 1) != 0 ||
		this->KeyDown(SDL_SCANCODE_S)
		);
}

bool InputManager::MouseClick() {
	return (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT));
}

void InputManager::getGamePad() {
	if (SDL_Init(SDL_INIT_GAMECONTROLLER) < 0) {
		std::cout << ("SDL could not initialize", SDL_GetError()) << "\n";
	}

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		std::cout << "linear texture filtering not enabled\n";
	}

	if (SDL_NumJoysticks() < 1) {
		std::cout << "no joysticks connected\n";
	}
	else {
		for (int i = 0; i < SDL_NumJoysticks(); i++) {
			if (SDL_IsGameController(i)) {
				gameController = SDL_GameControllerOpen(i);
				std::cout << SDL_GameControllerMapping(gameController) << "\n";
				break;
			}
		}

		if (gameController == NULL) {
			std::cout << "Couldnt open game controller";
		}
		else {
			std::cout << "Got controller!";
		}
	}
}