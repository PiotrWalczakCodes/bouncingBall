#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Entity
{
public:
	Entity(float xPosition, float yPosition, SDL_Texture* texture);
	float getX();
	float getY();
	SDL_Rect getCurrentFrame();
	SDL_Texture* getTex();
	void move(int windowSizeX, int windowSizeY);
private:
	float x, y;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};