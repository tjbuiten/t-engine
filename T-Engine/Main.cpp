#include "SDL.h"
#include "SDL_image.h"
#include "GameManager.hpp"
#include <iostream>
#include "Level.hpp"
#include "LevelLoader.hpp"

int main(int argc, char* argv[]) {
	GameManager gameManager;

	if (!gameManager.init("T-Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, false))
		return 0;

	LevelLoader loader;
	Level level;
	loader.loadLevel(".\\Assets\\LevelData\\#01.txt", gameManager.renderer, level);

	gameManager.addEntity(&level);

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


//Texture texture;

//SDL_Surface* tmpSurface = IMG_Load(".\\Assets\\Sprites\\IsometricFullTile.png");
//texture.texture = SDL_CreateTextureFromSurface(gameManager.renderer, tmpSurface);
//SDL_FreeSurface(tmpSurface);

//texture.destination.h = 64;
//texture.destination.w = 64;
//texture.destination.x = 350;
//texture.destination.y = 50;

//Entity ground = Entity(texture, 200, 200);
//Entity groundTwo = ground;
//Entity groundThree = ground;
//Entity groundFour = ground;
//Entity groundFive = ground;
//Entity groundSix = ground;
//Entity groundSeven = ground;
//Entity groundEight = ground;
//Entity groundNine = ground;
//Entity groundTen = ground;
//groundTwo.setPosition(232, 216);
//groundThree.setPosition(264, 232);
//groundFour.setPosition(168, 216);
//groundFive.setPosition(200, 232);
//groundSix.setPosition(232, 248);
//groundSeven.setPosition(136, 232);
//groundEight.setPosition(168, 248);
//groundNine.setPosition(200, 264);
//groundTen.setPosition(200, 168);

//gameManager.addEntity(ground);
//gameManager.addEntity(groundTwo);
//gameManager.addEntity(groundThree);
//gameManager.addEntity(groundFour);
//gameManager.addEntity(groundFive);
//gameManager.addEntity(groundSix);
//gameManager.addEntity(groundSeven);
//gameManager.addEntity(groundEight);
//gameManager.addEntity(groundNine);

//Texture textureTwo;

//tmpSurface = IMG_Load(".\\Assets\\Sprites\\TreeOne.png");
//textureTwo.texture = SDL_CreateTextureFromSurface(gameManager.renderer, tmpSurface);
//SDL_FreeSurface(tmpSurface);

//textureTwo.destination.h = 256;
//textureTwo.destination.w = 194;
//textureTwo.destination.x = 350;
//textureTwo.destination.y = 50;
//Entity tree = Entity(textureTwo, 136, 30);

//gameManager.addEntity(tree);