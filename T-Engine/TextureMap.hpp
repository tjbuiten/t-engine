#pragma once
#include <map>
#include "SDL.h"
#include "SDL_image.h"

class TextureMap {
public:
	TextureMap();
	~TextureMap();

	std::map<char, SDL_Texture*> textures;
	SDL_Rect srcRect, destRect;
};