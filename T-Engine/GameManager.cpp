#include "GameManager.hpp"
#include "Enemy.hpp"
#include <iostream>

SDL_Renderer* GameManager::renderer = nullptr;

bool GameManager::init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen) {
	int flags = (fullScreen) ? SDL_WINDOW_FULLSCREEN : SDL_WINDOWEVENT_NONE;

	window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_OPENGL);

	if (!window)
		return false;
	
	renderer = SDL_CreateRenderer(window, -1, 0);

	if (!renderer)
		return false;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderClear(renderer);

	running = true;

	return true;
};

bool GameManager::isRunning() {
	return running;
}

void GameManager::addEntity(Entity* entity) {
	GameManager::entities.push_back(entity);
}

void GameManager::nextFrame() {
	handleEvents();
	update();
	handleCollissions();
	render();
}

void GameManager::handleEvents() {
	this->eventBus->handleEvents();
}

void GameManager::update() {
	for (Entity* entity : this->entities)
		entity->update();
}

void GameManager::handleCollissions() {
	for (Entity* entity : this->entities) {
		if (entity == player)
			continue;

		if (entity->collisionCheck(player)) {
			std::vector<Entity*>::iterator p;

			p = std::find(this->entities.begin(), this->entities.end(), entity);

			if (p != this->entities.end()) {
				delete entity;
				entity = NULL;
				this->entities.erase(p);
			}
		};
	}
}

void GameManager::render() {
	SDL_RenderClear(renderer);

	for (Entity* entity : this->entities)
		entity->render(this->renderer);

	SDL_RenderPresent(this->renderer);
}

Enemy* GameManager::spawnEnemy(Player* player)
{
	SDL_Surface* tmpSurface = IMG_Load(".\\Assets\\Sprites\\SwordSwingEnemyAnimation.png");
	Enemy* enemy = new Enemy();
	enemy->texture = SDL_CreateTextureFromSurface(this->renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	enemy->destination.h = 111;
	enemy->destination.w = 111;
	enemy->destination.x = 100;
	enemy->destination.y = 450;
	enemy->player = player;

	return enemy;
}

Player* GameManager::spawnPlayer()
{
	SDL_Surface* tmpSurface = IMG_Load(".\\Assets\\Sprites\\SwordSwingAnimation.png");
	Player* player = new Player();
	player->texture = SDL_CreateTextureFromSurface(this->renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	player->destination.h = 111;
	player->destination.w = 111;
	player->destination.x = 608;
	player->destination.y = 450;
	player->inputManager.getGamePad();

	this->player = player;

	return player;
}