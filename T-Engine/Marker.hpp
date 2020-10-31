#pragma once
#include "Entity.hpp"

class Marker : public Entity {
private:
	bool visible = false;
	SDL_Rect textureOrigin;
	int frames = 0;
	int verticalDirection = 0;
	int horizontalDirection = 0;
public:
	Marker(SDL_Texture* texture, SDL_Rect position, SDL_EventBus* eventBus, CollissionManager* collissionManager) : Entity(texture, position, eventBus, collissionManager) {
		eventBus->subscribe(SDL_JOYAXISMOTION, this);

		this->textureOrigin.h = 64;
		this->textureOrigin.w = 64;
		this->textureOrigin.x = 0;
		this->textureOrigin.y = 0;
	};

	virtual void update();
	virtual void render(SDL_Renderer* renderer);

	void display();
	void hide();
	bool isVisible();
	void handleEvent(int eventType, SDL_Renderer* renderer, SDL_Event* event);
	void handleJoystickInput(SDL_Event* event);
};