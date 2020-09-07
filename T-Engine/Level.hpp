#pragma once
#include "Room.hpp"
#include "TextureMap.hpp"
#include <vector>
#include <string>

class Level {
public:
	Level(std::string roomsDirectory, std::string textureDirectory, int tileRowLength, int roomRowLength);
	~Level();

	const int tileRowLength;
	const int roomRowLength;
	const std::string roomsDirectory;
	const std::string textureDirectory;
	std::vector<Room> rooms;
	TextureMap textureMap;


private:
};