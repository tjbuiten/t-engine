//#include "TextureManager.hpp"
//
//SDL_Texture* TextureManager::LoadTexture(const char* texture) {
//	SDL_Surface* tmpSurface = IMG_Load(".\\Assets\\Sprites\\TestPlayer.png");
//	SDL_Texture* playerTexture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
//	SDL_FreeSurface(tmpSurface);
//
//	return playerTexture;
//}
//
//void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
//{
//	SDL_RenderCopy(Game::renderer, texture, &src, &dest);
//}
