#include "TextureManager.hpp"
#include <iostream>

SDL_Texture* TextureManager::LoadTexture(const char* textureLocation) {
	SDL_Surface* tmpSurface = IMG_Load(textureLocation);

	if (tmpSurface == NULL) {
		std::cout << "NO TEXTURE: " << IMG_GetError() << "\n";
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);

	if (!texture) {
		std::cout << "NO TEXTURE: " << IMG_GetError() << "\n";
	}

	SDL_FreeSurface(tmpSurface);

	return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, texture, NULL, &dest);
}