#pragma once
#include "Entity.hpp"
#include <vector>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "InputManager.hpp"

class Player : public Entity {
public:

	Player();
	~Player();

	virtual void Update();
};