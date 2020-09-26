# pragma once

#include "SDL.h"

class InputManager {
public:
	InputManager();
	~InputManager();
	bool KeyDown(SDL_Scancode scanCode);
	void Update();

private:
	const Uint8* keyboardStates;
};