#include "InputManager.hpp"

bool InputManager::KeyDown(SDL_Scancode scanCode) {
	return SDL_GetKeyboardState(NULL)[scanCode];
}