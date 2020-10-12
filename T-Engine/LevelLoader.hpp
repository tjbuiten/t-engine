#pragma once
#include "Level.hpp"
#include "Tile.hpp"
#include <string>
#include <fstream>
#include <SDL_image.h>
#include <filesystem>

class LevelLoader {
public:
	void loadLevel(std::string dataDirectory, SDL_Renderer* renderer, Level& level);

private:
	std::map<char, Tile> loadTiles(std::string textureDirectory, SDL_Renderer* renderer);
};