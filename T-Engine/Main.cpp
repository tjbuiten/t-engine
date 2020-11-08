#include "SDL.h"
#include "SDL_image.h"
#include "SDL_EventBus.hpp"
#include "SDL_EventsHandler.hpp"
#include "Player.hpp"
#include "Dummy.hpp"
#include "Ground.hpp"
#include "Background.hpp"
#include "GameManager.hpp"
#include "CollissionManager.hpp"
#include "Event.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	const int SCREEN_FPS = 60;
	const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
	Uint32 frameStart;
	int frameTime;

	GameManager gameManager;
	gameManager.initialize("T-Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 640, false);

	SDL_EventBus eventBus = SDL_EventBus(gameManager.renderer);
	SDL_EventsHandler* eventsHandler = new SDL_EventsHandler(&gameManager);
	CollissionManager collissionManager;

	eventBus.subscribe(SDL_QUIT, eventsHandler);

	SDL_Surface* surface = IMG_Load(".\\Assets\\Sprites\\Player.png");
	SDL_Rect* playerPosition = new SDL_Rect();
	playerPosition->h = 100;
	playerPosition->w = 64;
	playerPosition->x = 608;
	playerPosition->y = 100;

	SDL_Texture* playerTexture = SDL_CreateTextureFromSurface(gameManager.renderer, surface);

	//Dummy* dummy = gameManager.initializeDummy(&eventBus, &collissionManager);

	surface = IMG_Load(".\\Assets\\Sprites\\Background.png");

	SDL_Rect* backgroundPosition = new SDL_Rect();
	backgroundPosition->h = 640;
	backgroundPosition->w = 1280;
	backgroundPosition->x = 0;
	backgroundPosition->y = 0;

	Background background = Background(
		SDL_CreateTextureFromSurface(gameManager.renderer, surface),
		*backgroundPosition,
		&eventBus
	);

	surface = IMG_Load(".\\Assets\\Sprites\\Ground.png");

	SDL_Rect* groundPosition = new SDL_Rect();
	groundPosition->h = 320;
	groundPosition->w = 640;
	groundPosition->x = 0;
	groundPosition->y = 352;

	SDL_Rect* groundCollider = new SDL_Rect();
	groundCollider->h = 128;
	groundCollider->w = groundPosition->w;
	groundCollider->x = groundPosition->x;
	groundCollider->y = groundPosition->y + 200;

	Ground ground = Ground(
		SDL_CreateTextureFromSurface(gameManager.renderer, surface),
		*groundPosition,
		&eventBus,
		&collissionManager,
		*groundCollider
	);
	ground.addTagg(taggs::ground);
	ground.addTagg(taggs::wall);

	SDL_Rect* groundPosition2 = new SDL_Rect();
	groundPosition2->h = 320;
	groundPosition2->w = 640;
	groundPosition2->x = 640;
	groundPosition2->y = 352;

	SDL_Rect* groundCollider2 = new SDL_Rect();
	groundCollider2->h = 128;
	groundCollider2->w = groundPosition2->w;
	groundCollider2->x = groundPosition2->x;
	groundCollider2->y = groundPosition2->y + 200;


	Ground ground2 = Ground(
		SDL_CreateTextureFromSurface(gameManager.renderer, surface),
		*groundPosition2,
		&eventBus,
		&collissionManager,
		*groundCollider2
	);
	ground2.addTagg(taggs::ground);
	ground2.addTagg(taggs::wall);

	SDL_Rect* groundPosition3 = new SDL_Rect();
	groundPosition3->h = 320;
	groundPosition3->w = 640;
	groundPosition3->x = 640;
	groundPosition3->y = 256;

	SDL_Rect* groundCollider3 = new SDL_Rect();
	groundCollider3->h = 128;
	groundCollider3->w = groundPosition3->w;
	groundCollider3->x = groundPosition3->x;
	groundCollider3->y = groundPosition3->y + 200;

	Ground ground3 = Ground(
		SDL_CreateTextureFromSurface(gameManager.renderer, surface),
		*groundPosition3,
		&eventBus,
		&collissionManager,
		*groundCollider3
	);
	ground3.addTagg(taggs::ground);
	ground3.addTagg(taggs::wall);

	SDL_Rect* groundPosition4 = new SDL_Rect();
	groundPosition4->h = 320;
	groundPosition4->w = 640;
	groundPosition4->x = -640;
	groundPosition4->y = 160;

	SDL_Rect* groundCollider4 = new SDL_Rect();
	groundCollider4->h = 16;
	groundCollider4->w = groundPosition4->w;
	groundCollider4->x = groundPosition4->x;
	groundCollider4->y = groundPosition4->y + 200;

	Ground ground4 = Ground(
		SDL_CreateTextureFromSurface(gameManager.renderer, surface),
		*groundPosition4,
		&eventBus,
		&collissionManager,
		*groundCollider4
	);

	SDL_Rect* groundPosition7 = new SDL_Rect();
	groundPosition7->h = 320;
	groundPosition7->w = 640;
	groundPosition7->x = -640;
	groundPosition7->y = 64;

	SDL_Rect* groundCollider7 = new SDL_Rect();
	groundCollider7->h = 16;
	groundCollider7->w = groundPosition7->w;
	groundCollider7->x = groundPosition7->x;
	groundCollider7->y = groundPosition7->y + 200;

	Ground ground7 = Ground(
		SDL_CreateTextureFromSurface(gameManager.renderer, surface),
		*groundPosition7,
		&eventBus,
		&collissionManager,
		*groundCollider7
	);
	ground7.addTagg(taggs::ground);

	SDL_Rect* groundPosition5 = new SDL_Rect();
	groundPosition5->h = 320;
	groundPosition5->w = 640;
	groundPosition5->x = -640;
	groundPosition5->y = 352;

	SDL_Rect* groundCollider5 = new SDL_Rect();
	groundCollider5->h = 128;
	groundCollider5->w = groundPosition5->w;
	groundCollider5->x = groundPosition5->x;
	groundCollider5->y = groundPosition5->y + 200;

	Ground ground5 = Ground(
		SDL_CreateTextureFromSurface(gameManager.renderer, surface),
		*groundPosition5,
		&eventBus,
		&collissionManager,
		*groundCollider5
	);
	ground5.addTagg(taggs::wall);

	SDL_Rect* groundPosition6 = new SDL_Rect();
	groundPosition6->h = 320;
	groundPosition6->w = 640;
	groundPosition6->x = -640;
	groundPosition6->y = 256;

	SDL_Rect* groundCollider6 = new SDL_Rect();
	groundCollider6->h = 128;
	groundCollider6->w = groundPosition6->w;
	groundCollider6->x = groundPosition6->x;
	groundCollider6->y = groundPosition6->y + 200;

	Ground ground6 = Ground(
		SDL_CreateTextureFromSurface(gameManager.renderer, surface),
		*groundPosition6,
		&eventBus,
		&collissionManager,
		*groundCollider6
	);
	ground6.addTagg(taggs::ground);
	ground6.addTagg(taggs::wall);

	surface = IMG_Load(".\\Assets\\Sprites\\Marker.png");

	SDL_Rect* markerPosition = new SDL_Rect();
	markerPosition->h = 64;
	markerPosition->w = 64;
	markerPosition->x = 0;
	markerPosition->y = 0;

	Marker marker = Marker(
		SDL_CreateTextureFromSurface(gameManager.renderer, surface),
		*markerPosition,
		&eventBus,
		&collissionManager,
		0,
		0
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
			eventBus.handleEvent(new Event(event.type, &event));
		}

		eventBus.handleEvent(new Event(events::update));
		eventBus.handleEvent(new Event(events::render));

		SDL_RenderPresent(gameManager.renderer);

		frameTime = SDL_GetTicks() - frameStart;

		if (SCREEN_TICKS_PER_FRAME > frameTime) {
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTime);
		}
	}

	return 0;
}