#include "Level.hpp"

void Level::render(SDL_Renderer* renderer) {
	for (std::vector<std::vector<Tile>> layer: this->tiles) {
		for (std::vector<Tile> row : layer) {
			for (Tile tile : row) {
				SDL_Rect destination = tile.destination;
				destination.x += Level::cameraX;
				destination.y += Level::cameraY;
				SDL_RenderCopy(renderer, tile.texture, NULL, &destination);
			}
		}
	}
}

void Level::update() {
	if (Level::inputManager.KeyDown(SDL_SCANCODE_W)) {
		Level::cameraY++;
	}
	if (Level::inputManager.KeyDown(SDL_SCANCODE_S)) {
		Level::cameraY--;
	}
	if (Level::inputManager.KeyDown(SDL_SCANCODE_A)) {
		Level::cameraX++;
	}
	if (Level::inputManager.KeyDown(SDL_SCANCODE_D)) {
		Level::cameraX--;
	}
}