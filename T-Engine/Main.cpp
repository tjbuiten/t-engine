#include "Level.hpp"
#include "LevelLoader.hpp"
#include "Game.hpp"
#include "Player.hpp"
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
	game->init("2d-engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, false);

	Level* level = new Level(".\\Assets\\Rooms", ".\\Assets\\Textures\\TextureMapping.txt", 16, 1);
	LevelLoader levelLoader; 
	levelLoader.LoadLevel(*level);
	level->renderer = game->renderer;
	level->Render();

	TextureManager* tm = new TextureManager();

	SDL_Rect playerDestination;
	playerDestination.h = 32;
	playerDestination.w = 64;
	playerDestination.x = 0;
	playerDestination.y = 0;

	Player* player = &level->player;
	player->texture = tm->LoadTexture(".\\Assets\\Sprites\\IsoTestPlayer.png");
	player->destination = playerDestination;
	player->renderer = game->renderer;

	game->entities.push_back(level);

	while (game->running()) {
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();

		frameTime = SDL_GetTicks() - frameStart;

		if (FRAME_DELAY > frameTime) {
			SDL_Delay(FRAME_DELAY - frameTime);
		}
	}

	game->clean();

	return 0;
}