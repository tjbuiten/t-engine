#pragma once

#define Game_hpp

#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include "Entity.hpp"

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);

	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();

	static SDL_Renderer* renderer;
	std::vector<Entity*> entities;


private:
	bool isRunning;
	SDL_Window* window;
};