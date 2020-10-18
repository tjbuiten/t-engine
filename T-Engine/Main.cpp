#include "SDL.h"
#include "SDL_image.h"
#include "GameManager.hpp"
#include <iostream>
#include "Level.hpp"
#include "LevelLoader.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

int main(int argc, char* argv[]) {
	GameManager gameManager;

	if (!gameManager.init("T-Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 640, false))
		return 0;

	LevelLoader loader;
	Level level;
	loader.loadLevel(".\\Assets\\LevelData\\#01.txt", gameManager.renderer, level);

	gameManager.addEntity(&level);

	Player* player = gameManager.spawnPlayer();
	gameManager.addEntity(player);

	Enemy* enemy = gameManager.spawnEnemy(player);
	gameManager.addEntity(enemy);
	
	SDL_GLContext mainContext = SDL_GL_CreateContext(gameManager.window);
	
	const int SCREEN_FPS = 60;
	const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
	Uint32 frameStart;
	int frameTime;

	while (gameManager.isRunning()) {
		frameStart = SDL_GetTicks();
		
		gameManager.handleEvents();
		gameManager.nextFrame();

		frameTime = SDL_GetTicks() - frameStart;

		if (SCREEN_TICKS_PER_FRAME > frameTime) {
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTime);
		}
	}

	return 0;
}

void initialize(GameManager gm) {

}