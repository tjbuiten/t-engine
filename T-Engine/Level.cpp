#include "Level.hpp"

void Level::render(SDL_Renderer* renderer) {
	for (std::vector<std::vector<Tile>> layer: this->tiles) {
		for (std::vector<Tile> row : layer) {
			for (Tile tile : row) {
				tile.destination.x += Level::cameraX;
				tile.destination.y += Level::cameraY;
				SDL_RenderCopy(renderer, tile.texture, NULL, &tile.destination);
			}
		}
	}
}

void Level::update() {
	/*if (Level::inputManager.KeyDown(SDL_SCANCODE_A)) {
		Level::cameraX++;
	}
	if (Level::inputManager.KeyDown(SDL_SCANCODE_D)) {
		Level::cameraX--;
	}*/
}

bool Level::collisionCheck(Collider* collider) {
	return false;
}