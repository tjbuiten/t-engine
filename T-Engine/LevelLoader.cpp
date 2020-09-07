#include <iostream>
#include <vector>
#include "LevelLoader.hpp"
#include <fstream>
#include <filesystem>
#include "SDL.h"
#include "SDL_image.h"
#include "TextureMap.hpp"

namespace fs = std::filesystem;

using namespace std;

LevelLoader::LevelLoader() {
}

LevelLoader::~LevelLoader() {
}

void LevelLoader::LoadLevel(Level& level) {
	TextureMap textureMap;

	for (const fs::directory_entry& entry : fs::directory_iterator(level.textureDirectory)) {
		std::pair<char, SDL_Texture*> x = LoadTexture(entry.path().string());
		textureMap.textures[x.first] = x.second;
	}

	level.textureMap = textureMap;

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
			room.tiles.push_back(line);
		}

		myfile.close();
	}

	return room;
}

std::pair<char, SDL_Texture*> LevelLoader::LoadTexture(string texturesDirectory) {
	ifstream myfile(texturesDirectory);

	char character = '*';
	string textureDirectory = "";

	if (myfile.is_open())
	{
		string line;
		string lastLine = "";

		while (getline(myfile, line))
		{
			if (lastLine == "CHAR")
				character = line[0];

			if (lastLine == "TEXTURE")
				textureDirectory = line;

			lastLine = line;
		}

		myfile.close();
	}

	SDL_Surface* tmpSurface = IMG_Load(textureDirectory.c_str());
	SDL_Texture* playerTexture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return std::make_pair(character, playerTexture);
};