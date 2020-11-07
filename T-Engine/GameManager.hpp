#pragma once
#include "SDL.h"
#include "Dummy.hpp"
#include "SDL_EventBus.hpp"
#include "CollissionManager.hpp"

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

	Dummy* initializeDummy(SDL_EventBus* eventBus, CollissionManager* collissionManager);
};