#include "Level.hpp"
#include "LevelLoader.hpp"
#include "Game.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.hpp"

Game* game = nullptr;

int main(int argc, char* argv[]) {
	const int FPS = 60;
	const int FRAME_DELAY = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("2d-engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	Level* level = new Level(".\\Assets\\Rooms", ".\\Assets\\Textures", 5, 2);
	LevelLoader levelLoader; 
	levelLoader.LoadLevel(*level);

	TextureManager textureManager;
	textureManager.DrawLevel(*level);

	while (game->running()) {
		frameStart = SDL_GetTicks();
		/*
		game->handleEvents();
		game->update();
		game->render();
		*/
		frameTime = SDL_GetTicks() - frameStart;

		if (FRAME_DELAY > frameTime) {
			SDL_Delay(FRAME_DELAY - frameTime);
		}
	}

	game->clean();

	return 0;
}