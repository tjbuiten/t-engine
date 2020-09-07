#include "Game.hpp"
#include <iostream>
#include "GameObject.hpp"

GameObject* player;
SDL_Renderer* Game::renderer = nullptr;

Game::Game() {
	isRunning = false;
}

Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen) {
    int flags = 0;

	if (fullScreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialized..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window)
			std::cout << "Window created..." << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created..." << std::endl;
		}

		isRunning = true;
	}

	//player = new GameObject(".\\Assets\\Sprites\\TestPlayer.png", 0, 0);
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {
	//player->Update();
}

void Game::render() {
	//SDL_RenderClear(renderer);
	//player->Render();
	//SDL_RenderPresent(renderer);
}

void Game::clean() {

}

bool Game::running() {
	return isRunning;
}