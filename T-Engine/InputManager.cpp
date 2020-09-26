#include "InputManager.hpp"

InputManager::InputManager() {};

InputManager::~InputManager() {};

bool InputManager::KeyDown(SDL_Scancode scanCode) {
	return keyboardStates[scanCode];
}

void InputManager::Update() {
	keyboardStates = SDL_GetKeyboardState(NULL);
}