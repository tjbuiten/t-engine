#pragma once
#include <map>
#include "SDL.h"
#include "SDL_image.h"
#include "Texture.hpp"

class TextureMap {
public:
	TextureMap();
	~TextureMap();

	std::map<char, Texture> textures;
};