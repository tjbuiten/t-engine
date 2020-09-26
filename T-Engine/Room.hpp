#pragma once
#include <vector>
#include "Layer.hpp"

class Room {
public:
	Room();
	~Room();

	std::vector<Layer> layers;
private:
};