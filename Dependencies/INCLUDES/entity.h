#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Entity
{
public:
	Entity(float xPosition, float yPosition, SDL_Texture* texture);
	Entity();
	float getX();
	float getY();

	void changeX(float change);
	void changeY(float change);

	SDL_Rect getCurrentFrame();
	SDL_Texture* getTex();
private:
	float x, y;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};