#pragma once
#include "SDL.h"
#include "SDL_image.h"

class Texture {
public:
	SDL_Rect destination;
	SDL_Texture* texture;
};