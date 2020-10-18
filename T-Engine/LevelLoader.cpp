#include "LevelLoader.hpp"
#include <iostream>

void LevelLoader::loadLevel(std::string dataDirectory, SDL_Renderer* renderer, Level& level) {
	std::ifstream levelData(dataDirectory);

	std::string levelDirectory = "";
	std::string textureDirectory = "";

	if (levelData.is_open()) {
		std::string line;
		std::string lastLine = "";

		while (std::getline(levelData, line)) {
			if (line[0] == '#')
				continue;

			(levelDirectory == "") ? levelDirectory = line : textureDirectory = line;
		}
	}

	if (levelDirectory == "" || textureDirectory == "")
		return;

	level.textureMap = this->loadTiles(textureDirectory, renderer);

	int layers = 0;

	for (const auto& path : std::filesystem::directory_iterator(levelDirectory)) {
		std::ifstream tileFile(path);

		if (tileFile.is_open()) {
			std::string line;
			std::vector<std::vector<Tile>> layer;
			level.tiles.push_back(layer);

			int rows = 0;

			while (std::getline(tileFile, line)) {
				std::vector<Tile> row;
				int x = -64;
				int y = 64 + 64 * rows;

				for (char& c : line) {
					std::map<char, Tile>::iterator mappedTexture = level.textureMap.find(c);

					x += 64;

					if (mappedTexture == level.textureMap.end())
						continue;

					Tile texture = mappedTexture->second;
					texture.destination.x = x;
					texture.destination.y = y - texture.destination.h;

					row.push_back(texture);
				}

				level.tiles.back().push_back(row);
				rows++;
			}

			layers++;
		}
	}
}

std::map<char, Tile> LevelLoader::loadTiles(std::string textureDirectory, SDL_Renderer* renderer) {
	std::map<char, Tile> textureMap;

	std::ifstream textureFile(textureDirectory);

	if (textureFile.is_open()) {
		std::string line;

		while (std::getline(textureFile, line)) {
			char character = line[0];

			line = line.erase(0, 2);

			std::size_t nextBlock = line.find(';');

			SDL_Surface* tmpSurface = IMG_Load(line.substr(0, nextBlock).c_str());

			Tile texture;
			texture.texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
			SDL_FreeSurface(tmpSurface);

			texture.destination.h = 64;
			texture.destination.w = 64;
			texture.destination.x = 0;
			texture.destination.y = 0;


			if (nextBlock == std::string::npos) {
				textureMap[character] = texture;
				continue;
			}

			line = line.erase(0, nextBlock + 1);
			nextBlock = line.find(';');

			if (nextBlock != std::string::npos) {
				texture.destination.w = stoi(line.substr(0, nextBlock));
				
				line = line.erase(0, nextBlock + 1);
				
				texture.destination.h = stoi(line);
			}

			textureMap[character] = texture;
		}
	}

	return textureMap;
}