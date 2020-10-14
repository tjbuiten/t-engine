#include "InputManager.hpp"

bool InputManager::KeyDown(SDL_Scancode scanCode) {
	return SDL_GetKeyboardState(NULL)[scanCode];
}

bool InputManager::MouseClick() {
	return (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT));
}