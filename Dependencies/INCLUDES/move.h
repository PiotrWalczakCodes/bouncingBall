#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "entity.h"
#include "windowRender.h"
#include "renderFloor.h"

void move(Entity& entity, RenderWindow& window, int winSizeX, int winSizeY)
{
	const Uint8* state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_W])
	{
		float startSpeed = 8.0;

		while (startSpeed > 0)
		{
			entity.changeY(entity.getY() - startSpeed);
			SDL_Delay(10);
			startSpeed -= 0.2;

			const Uint8* tempState = SDL_GetKeyboardState(NULL);
			if (tempState[SDL_SCANCODE_A])
			{
				float speed = 4;
				entity.changeX(entity.getX() - speed);
			}

			if (tempState[SDL_SCANCODE_D])
			{
				float speed = 4;
				entity.changeX(entity.getX() + speed);
			}

			window.clear();
			renderFloor(window);
			window.render(entity);
			window.display();


		}

		startSpeed = 0.0;

		while (entity.getY() < winSizeY - 48 * 4*2)
		{
			entity.changeY(entity.getY() + startSpeed);
			SDL_Delay(10);
			startSpeed += 0.2;

			const Uint8* tempState = SDL_GetKeyboardState(NULL);
			if (tempState[SDL_SCANCODE_A])
			{
				float speed = 4;
				entity.changeX(entity.getX() - speed);
			}
			if (tempState[SDL_SCANCODE_D])
			{
				float speed = 4;
				entity.changeX(entity.getX() + speed);
			}

			window.clear();
			renderFloor(window);
			window.render(entity);
			window.display();


		}

		entity.changeY(winSizeY - 48 * 4*2);

	}

	if (state[SDL_SCANCODE_A])
	{
		float speed = 0.6;
		entity.changeX(entity.getX() - speed);

		window.clear();
		renderFloor(window);
		window.render(entity);
		window.display();



	}

	if (state[SDL_SCANCODE_D])
	{
		float speed = 0.6;
		entity.changeX(entity.getX() + speed);

		window.clear();
		renderFloor(window);
		window.render(entity);
		window.display();

	}
}