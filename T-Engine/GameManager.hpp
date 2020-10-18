#pragma once
#include <vector>
#include "Entity.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include "Player.hpp"
#include "Enemy.hpp"

class GameManager {
private:
	bool running;
	void update();
	void render();
	int x = 0;
public:
	SDL_Window* window;
	std::vector<Entity*> entities;
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
	bool isRunning();
	void handleEvents();
	void nextFrame();
	void addEntity(Entity* entity);
	static SDL_Renderer* renderer;
	void removeEntity(Entity* entity);
	Enemy* spawnEnemy(Player* player);
	Player* spawnPlayer();
	void handleCollissions();
	Player* player;
};