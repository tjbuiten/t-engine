#include "SDL.h"
#include "SDL_image.h"
#include "Game.hpp"

class Entity {
public:
	SDL_Rect destination; 
	SDL_Texture* texture;

	Entity();
	~Entity();
	
	virtual void Render() {
		SDL_RenderCopy(Game::renderer, texture, NULL, &destination);
	};
};