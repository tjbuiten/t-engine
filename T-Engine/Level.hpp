#pragma once
#include "Room.hpp"
#include "Entity.hpp"
#include "Layer.hpp"
#include "Player.hpp"
#include "TextureMap.hpp"
#include <vector>
#include <string>

class Level : public Entity {
public:
	Level(std::string roomsDirectory, std::string textureDirectory, int tileRowLength, int roomRowLength);
	~Level();
	virtual void Render();

	const int tileRowLength;
	const int roomRowLength;
	const std::string roomsDirectory;
	const std::string textureDirectory;
	Player player;
	std::vector<Room> rooms;
	TextureMap textureMap;

private:
};