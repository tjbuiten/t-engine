#include "TextureManager.hpp"
#include <iostream>

SDL_Texture* TextureManager::LoadTexture(const char* textureLocation) {
	SDL_Surface* tmpSurface = IMG_Load(textureLocation);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, texture, NULL, &dest);
}

void TextureManager::DrawLevel(Level& level) {
	int rectHeight = 32;
	int rectWidth = 32;

	SDL_Rect destination;
	destination.h = 32;
	destination.w = 32;
	destination.x = 0;
	destination.y = 0;

	TextureMap textureMap = level.textureMap;

	int roomRows = 0;

	for (int i = 0; i < level.rooms.size(); i++) {
		int tileRows = 0;

		for (int j = 0; j < level.rooms[i].tiles.size(); j++) {
			std::string line = level.rooms[i].tiles[j];

			for (int k = 0; k < line.length(); k++) {
				destination.x = ((i - (roomRows * level.roomRowLength)) * level.tileRowLength) * rectWidth;
				destination.x += k * rectWidth;
				destination.y = ((roomRows * level.tileRowLength) + tileRows) * rectHeight;

				std::map<char, SDL_Texture*>::iterator it = textureMap.textures.find(line[k]);
				SDL_Texture * texture;

				if (it != textureMap.textures.end()) {
					Draw(it->second, destination);
				}
			}

			tileRows++;
		}

		if (i - (roomRows * level.roomRowLength) >= level.roomRowLength - 1) {
			roomRows++;
		}
	}

	SDL_RenderPresent(Game::renderer);
};
