#pragma once

#include "Game.hpp"
#include "Level.hpp"

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* texture);
	static void Draw(SDL_Texture* texture, SDL_Rect dest);
	static void DrawLevel(Level& level);
};