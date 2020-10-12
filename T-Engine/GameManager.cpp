#include "GameManager.hpp"

SDL_Renderer* GameManager::renderer = nullptr;

bool GameManager::init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen) {
	int flags = (fullScreen) ? SDL_WINDOW_FULLSCREEN : SDL_WINDOWEVENT_NONE;

	window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

	if (!window)
		return false;
	
	renderer = SDL_CreateRenderer(window, -1, 0);

	if (!renderer)
		return false;

	running = true;

	return true;
};

bool GameManager::isRunning() {
	return running;
}

void GameManager::addEntity(Entity* entity) {
	GameManager::entities.push_back(entity);
}

void GameManager::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		this->running = false;
		break;
	default:
		break;
	}
}

void GameManager::nextFrame() {
	update();
	render();
}

void GameManager::update() {
	for (Entity* entity : this->entities)
		entity->update();
}

void GameManager::render() {
	SDL_RenderClear(renderer);

	for (Entity* entity : this->entities)
		entity->render(this->renderer);

	SDL_RenderPresent(this->renderer);
}