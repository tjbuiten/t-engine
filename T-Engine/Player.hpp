#pragma once
#include "Entity.hpp"
#include "Collider.hpp"
#include "InputManager.hpp"
#include "Marker.hpp"
#include "SDL_EventHandlerInterface.hpp"
#include "SDL_EventBus.hpp"

class Player : public Entity, SDL_EventHandlerInterface {
private:
	float velocityX = 0;
	float velocityY = 0;
	int direction = 1;
	int frames = 0;
	bool jumping = false;
	bool dashing = false;
	bool attacking = false;
	bool isGrounded();
public:
	Player() {
		SDL_EventBus* eventBus = SDL_EventBus::getInstance();
		eventBus->subscribe(SDL_CONTROLLERBUTTONDOWN, this);
		eventBus->subscribe(SDL_CONTROLLERBUTTONUP, this);
	}

	InputManager inputManager;
	Marker* marker;
	SDL_Rect source;
	virtual void update();
	virtual void render(SDL_Renderer* renderer);
	virtual bool collisionCheck(Entity* entity);
	virtual void handleEvent(SDL_Event eventType);

	void throwMarker();
	void crouching();
	void jump();
	void releaseMarker();
};
