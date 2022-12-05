#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "entity.h"

class RenderWindow
{
public:
	RenderWindow(const char*, int, int);
	SDL_Texture* loadTexture(const char*);
	void clear();
	void render(Entity& entity);
	void display();
	void cleanUp();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};