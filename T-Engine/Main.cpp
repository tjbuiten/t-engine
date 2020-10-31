#include "SDL.h"
#include "SDL_image.h"
#include "SDL_EventBus.hpp"
#include "SDL_EventsHandler.hpp"
#include "Player.hpp"
#include "GameManager.hpp"
#include "CollissionManager.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	const int SCREEN_FPS = 60;
	const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
	Uint32 frameStart;
	int frameTime;

	GameManager gameManager;
	gameManager.initialize("T-Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 640, false);

	SDL_EventBus eventBus;
	SDL_EventsHandler* eventsHandler = new SDL_EventsHandler(&gameManager);
	CollissionManager collissionManager;

	eventBus.subscribe(SDL_QUIT, eventsHandler);

	SDL_Surface* surface = IMG_Load(".\\Assets\\Sprites\\Player.png");
	SDL_Rect* playerPosition = new SDL_Rect();
	playerPosition->h = 100;
	playerPosition->w = 64;
	playerPosition->x = 100;
	playerPosition->y = 100;

	SDL_Texture* playerTexture = SDL_CreateTextureFromSurface(gameManager.renderer, surface);

	surface = IMG_Load(".\\Assets\\Sprites\\Marker.png");

	SDL_Rect* markerPosition = new SDL_Rect();
	markerPosition->h = 64;
	markerPosition->w = 64;
	markerPosition->x = 0;
	markerPosition->y = 0;

	Marker marker = Marker(
		SDL_CreateTextureFromSurface(gameManager.renderer, surface),
		*markerPosition,
		&eventBus
	);

	Player player = Player(
		playerTexture,
		*playerPosition,
		&eventBus,
		&marker,
		&collissionManager
	);

	SDL_FreeSurface(surface);

	if (!gameManager.isRunning())
		return 0;

	while (gameManager.isRunning()) {
		frameStart = SDL_GetTicks();

		SDL_RenderClear(gameManager.renderer);

		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			eventBus.handleEvent(event.type, gameManager.renderer, &event);
		}

		eventBus.handleEvent(events::update, gameManager.renderer);
		eventBus.handleEvent(events::render, gameManager.renderer);

		SDL_RenderPresent(gameManager.renderer);

		frameTime = SDL_GetTicks() - frameStart;

		if (SCREEN_TICKS_PER_FRAME > frameTime) {
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTime);
		}
	}

	return 0;
}