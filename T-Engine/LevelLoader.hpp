#pragma once
#include "Level.hpp"
#include "Room.hpp"
#include <vector>
#include <string>
#include "SDL.h"
#include "SDL_image.h"

class LevelLoader {
public:
	LevelLoader();
	~LevelLoader();

	void LoadLevel(Level& level);

private:
	Room LoadRoom(std::string roomDirectory);
	std::pair<char, SDL_Texture*> LoadTexture(std::string texturesDirectory);
};