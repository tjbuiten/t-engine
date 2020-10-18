#pragma once
#include "Tile.hpp"
#include "Entity.hpp"
#include "InputManager.hpp"
#include <map>
#include <vector>

class Level: public Entity {
private:
	InputManager inputManager;
	int cameraX = 0;
	int cameraY = 0;
public:
	std::map<char, Tile> textureMap;
	std::vector<std::vector<std::vector<Tile>>> tiles;
	virtual void render(SDL_Renderer* renderer);
	virtual void update();
	virtual bool collisionCheck(Collider* collider);
};