#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "windowRender.h"
#include "entity.h"

RenderWindow::RenderWindow(const char* title, int w, int h)
	:window(nullptr), renderer(nullptr)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr)
	{
		std::cout << "Renderer failed to init. Error: " << SDL_GetError() << std::endl;
	}
}

SDL_Texture* RenderWindow::loadTexture(const char* filePath)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);

	if (texture == nullptr)
	{
		std::cout << "Texture failed to load. Error: " << SDL_GetError() << std::endl;
	}

	return texture;
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& entity)
{
	
	int renderScale = 4;

	SDL_Rect renderSource;
	renderSource.x = entity.getCurrentFrame().x;
	renderSource.y = entity.getCurrentFrame().y;
	renderSource.w = entity.getCurrentFrame().w;
	renderSource.h = entity.getCurrentFrame().h;

	SDL_Rect renderDest;

	renderDest.x = entity.getX();
	renderDest.y = entity.getY();
	renderDest.w = entity.getCurrentFrame().w * renderScale;
	renderDest.h = entity.getCurrentFrame().h * renderScale;
	
	SDL_RenderCopy(renderer, entity.getTex(), &renderSource, &renderDest);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
	std::cout << "Window closed" << std::endl;
}
