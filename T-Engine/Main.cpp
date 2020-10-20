#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"
#include "GameManager.hpp"
#include <iostream>
#include "Level.hpp"
#include "LevelLoader.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <stdio.h>

int main(int argc, char* argv[]) {
	GameManager gameManager;

	if (!gameManager.init("T-Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 640, false))
		return 0;

	LevelLoader loader;
	Level level;
	loader.loadLevel(".\\Assets\\LevelData\\#01.txt", gameManager.renderer, level);

	gameManager.addEntity(&level);

	Player* player = gameManager.spawnPlayer();
	player->marker = new Marker();
	SDL_Surface* tmpSurface = IMG_Load(".\\Assets\\Sprites\\Marker.png");
	player->marker->texture = SDL_CreateTextureFromSurface(gameManager.renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	player->marker->destination = player->destination;
	gameManager.addEntity(player);
	gameManager.addEntity(player->marker);

	Enemy* enemy = gameManager.spawnEnemy(player);
	gameManager.addEntity(enemy);
	
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	//SDL_GLContext mainContext = SDL_GL_CreateContext(gameManager.window);

	//glClearColor(1.f, 0.f, 1.f, 0.f);
	//glViewport(0, 0, 1280, 640);
	
	const int SCREEN_FPS = 60;
	const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
	Uint32 frameStart;
	int frameTime;

	while (gameManager.isRunning()) {
		frameStart = SDL_GetTicks();
		
		gameManager.handleEvents();
		gameManager.nextFrame();

		//glClear(GL_COLOR_BUFFER_BIT);

		//SDL_GL_SwapWindow(gameManager.window);

		frameTime = SDL_GetTicks() - frameStart;

		if (SCREEN_TICKS_PER_FRAME > frameTime) {
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTime);
		}
	}

	return 0;
}

void initialize(GameManager gm) {

}