#include <iostream>
#include <vector>
#include "LevelLoader.hpp"
#include <fstream>
#include <filesystem>
#include "SDL.h"
#include "SDL_image.h"
#include "TextureMap.hpp"
#include "Texture.hpp"
#include <string_view>
#include "Game.hpp"

using namespace std::string_view_literals;
namespace fs = std::filesystem;

using namespace std;

LevelLoader::LevelLoader() {
}

LevelLoader::~LevelLoader() {
}

void LevelLoader::LoadLevel(Level& level) {
	LoadTexture(level);

	for (const auto& entry : fs::directory_iterator(level.roomsDirectory)) {
		level.rooms.push_back(LoadRoom(entry.path().string()));
	}
}

Room LevelLoader::LoadRoom(string roomDirectory)
{
	ifstream myfile(roomDirectory);
	Room room;

	if (myfile.is_open())
	{
		string line;

		while (getline(myfile, line))
		{
			if (line == "LAYER") {
				Layer layer;
				room.layers.push_back(layer);
				continue;
			}

			if (room.layers.size() == 0) {
				continue;
			}

			room.layers.back().tiles.push_back(line);
		}

		myfile.close();
	}

	return room;
}

void LevelLoader::LoadTexture(Level& level) {
	TextureMap textureMap;
	ifstream myfile(level.textureDirectory);

	char character = '*';
	string textureDirectory = "";

	if (myfile.is_open())
	{
		string line;
		string lastLine = "";

		while (getline(myfile, line))
		{
			character = line[0];
			textureDirectory = line.erase(0,2);

			SDL_Surface* tmpSurface = IMG_Load(textureDirectory.c_str());
			SDL_Texture* playerTexture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
			SDL_FreeSurface(tmpSurface);

			SDL_Rect destination;
			destination.w = 64;
			destination.h = 32;

			std::size_t nextBlock = line.find(';');

			if (nextBlock != std::string::npos) {
				textureDirectory = line.substr(0, nextBlock);
				tmpSurface = IMG_Load(textureDirectory.c_str());
				playerTexture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
				SDL_FreeSurface(tmpSurface);

				line = line.erase(0, nextBlock + 1);

				std::size_t nextBlock = line.find(';');

				if (nextBlock != std::string::npos) {
					destination.w = stoi(line.substr(0, nextBlock));

					line = line.erase(0, nextBlock + 1);
					destination.h = stoi(line);
				}
			}

			Texture texture;
			texture.texture = playerTexture;

			texture.destination = destination;

			textureMap.textures[character] = texture;
		}

		myfile.close();
	}

	level.textureMap = textureMap;
};