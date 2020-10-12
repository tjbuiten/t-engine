#pragma once
#include <vector>
#include "Entity.hpp"
#include "SDL.h"
#include "SDL_image.h"

class GameManager {
private:
	std::vector<Entity*> entities;
	SDL_Window* window;
	bool running;
	void update();
	void render();
public:
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
	bool isRunning();
	void handleEvents();
	void nextFrame();
	void addEntity(Entity* entity);
	static SDL_Renderer* renderer;
};