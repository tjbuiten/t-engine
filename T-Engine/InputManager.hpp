#pragma once
#include "SDL.h"

class InputManager {
private:
	const int JOYSTICK_DEAD_ZONE = 8000;
public:
	SDL_GameController* gameController = NULL;

	bool KeyDown(SDL_Scancode scanCode);
	bool MovingLeft();
	bool MovingRight();
	bool Jumping();
	bool Crouching();
	bool MouseClick();
	void getGamePad();
};