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
	SDL_Texture* floorTex = window.loadTexture("res/gfx/floor.png");

	Entity planetEntity0((winSizeX - 48 * 4) / 2, winSizeY - 4*48*2, planetEarth);
	Entity floor0(0, 720 - (48 * 4), floorTex);
	Entity floor1(48 * 4, 720 - (48 * 4), floorTex);
	Entity floor2(48 * 4 * 2, 720 - (48 * 4), floorTex);
	Entity floor3(48 * 4 * 3, 720 - (48 * 4), floorTex);
	Entity floor4(48 * 4 * 4, 720 - (48 * 4), floorTex);
	Entity floor5(48 * 4 * 5, 720 - (48 * 4), floorTex);
	Entity floor6(48 * 4 * 6, 720 - (48 * 4), floorTex);


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