#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "entity.h"
#include "windowRender.h"

void icyMove(Entity& entity, RenderWindow& window)
{
	const Uint8* state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_RIGHT])
	{
		float startSpeed = 6.0;

		while (startSpeed > 0)
		{
			entity.changeX(entity.getX() + startSpeed);
			SDL_Delay(10);
			startSpeed -= 0.1;

			window.clear();
			window.render(entity);
			window.display();

		}
		
	}

	if (state[SDL_SCANCODE_LEFT])
	{
		float startSpeed = 6.0;

		while (startSpeed > 0)
		{
			entity.changeX(entity.getX() - startSpeed);
			SDL_Delay(10);
			startSpeed -= 0.1;

			window.clear();
			window.render(entity);
			window.display();

		}

	}

	if (state[SDL_SCANCODE_UP])
	{
		float startSpeed = 6.0;

		while (startSpeed > 0)
		{
			entity.changeY(entity.getY() - startSpeed);
			SDL_Delay(10);
			startSpeed -= 0.1;

			window.clear();
			window.render(entity);
			window.display();

		}

	}

	if (state[SDL_SCANCODE_DOWN])
	{
		float startSpeed = 6.0;

		while (startSpeed > 0)
		{
			entity.changeY(entity.getY() + startSpeed);
			SDL_Delay(10);
			startSpeed -= 0.1;

			window.clear();
			window.render(entity);
			window.display();

		}

	}
}