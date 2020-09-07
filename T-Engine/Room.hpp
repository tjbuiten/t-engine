#pragma once
#include "Game.hpp"
#include <vector>
#include <string>

class Room {
public:
	Room();
	~Room();

	std::vector<std::string> tiles;
private:
};