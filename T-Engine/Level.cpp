#include "Level.hpp"
#include <string>

Level::Level(std::string roomsDirectory, std::string textureDirectory, int tileRowLength, int roomRowLength): roomsDirectory(roomsDirectory),
	textureDirectory(textureDirectory),
	tileRowLength(tileRowLength),
	roomRowLength(roomRowLength)
	{ }

Level::~Level() {
}