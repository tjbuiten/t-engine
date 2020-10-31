#pragma once
#include "SDL.h"

class GameManager {
private:
	bool running = false;
	SDL_Window* window = NULL;

	void update();
	void render();
public:
	SDL_Renderer* renderer = NULL;
	void initialize(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
	bool isRunning();
	void quitGame();
};