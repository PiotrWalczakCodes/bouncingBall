#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "windowRender.h"
#include "entity.h"
#include "move.h"
#include "renderFloor.h"


int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		std::cout << "'SDL_Init' operation has failed. Error: " << SDL_GetError() << std::endl;
	}
	
	if (!(IMG_Init(IMG_INIT_PNG)))
	{
		std::cout << "'IMG_Init' operation has failed. Error: " << SDL_GetError() << std::endl;
	}

	int winSizeX = 1280;
	int winSizeY = 720;

	RenderWindow window("testWindow", winSizeX, winSizeY);

	SDL_Texture* planetEarth = window.loadTexture("res/gfx/Terran.png");

	Entity planetEntity0((winSizeX - 48 * 4) / 2, winSizeY - 4*48*2, planetEarth);

	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning) 
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		move(planetEntity0, window, winSizeX, winSizeY);

		window.clear();
		renderFloor(window);
		window.render(planetEntity0);
		window.display();
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}