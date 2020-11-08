#pragma once
#include "Entity.hpp"
#include <math.h>

class Marker : public Entity {
private:
	bool visible = false;
	SDL_Rect textureOrigin;
	int frames = 0;
	int verticalDirection = 0;
	int horizontalDirection = 0;
	double slice = 0;
public:
	int originX = 0;
	int originY = 0;

	Marker(SDL_Texture* texture, SDL_Rect position, SDL_EventBus* eventBus, CollissionManager* collissionManager, int originX, int originY) : Entity(texture, position, eventBus, collissionManager) {
		eventBus->subscribe(SDL_JOYAXISMOTION, this);

		this->textureOrigin.h = 64;
		this->textureOrigin.w = 64;
		this->textureOrigin.x = 0;
		this->textureOrigin.y = 0;
		this->originX = originX;
		this->originY = originY;
	};

	virtual void update();
	virtual void render(SDL_Renderer* renderer);

	void display();
	void hide();
	bool isVisible();
	void handleEvent(Event* event, SDL_Renderer* renderer);
	void handleJoystickInput(SDL_Event* event);
};