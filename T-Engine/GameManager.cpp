#include "GameManager.hpp"

void GameManager::initialize(const char* title, int xpos, int ypos, int width, int height, bool fullScreen) {
	int flags = (fullScreen) ? SDL_WINDOW_FULLSCREEN : SDL_WINDOWEVENT_NONE;

	this->window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

	if (!this->window)
		return;

	this->renderer = SDL_CreateRenderer(window, -1, 0);

	if (!this->renderer)
		return;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	this->running = true;

	SDL_Init(SDL_INIT_GAMECONTROLLER);

	for (int i = 0; i < SDL_NumJoysticks(); i++) {
		if (SDL_IsGameController(i)) {
			SDL_GameControllerOpen(i);
			break;
		}
	}
}

bool GameManager::isRunning() {
	return this->running;
}

void GameManager::quitGame() {
	this->running = false;
}

void GameManager::update() {

}

void GameManager::render() {

}