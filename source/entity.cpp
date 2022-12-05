#include "entity.h"

#include <SDL.h>
#include <SDL_image.h>

Entity::Entity(float xPosition, float yPosition, SDL_Texture* texture)
	:x(xPosition), y(yPosition), tex(texture)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 48;
	currentFrame.h = 48;
	
}

float Entity::getX()
{
	return x;
}

float Entity::getY()
{
	return y;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}

SDL_Texture* Entity::getTex()
{
	return tex;
}

void Entity::move(int windowSizeX, int windowSizeY)
{
	const Uint8* state = SDL_GetKeyboardState(NULL);

	float moveSpeed = 0.6;

	if (state[SDL_SCANCODE_W] && y > 0)
	{
		y -= moveSpeed;
	}
	if (state[SDL_SCANCODE_S] && y < windowSizeY - (48 * 4))
	{
		y += moveSpeed;
	}
	if (state[SDL_SCANCODE_A] && x > 0)
	{
		x -= moveSpeed;
	}
	if (state[SDL_SCANCODE_D] && x < windowSizeX - (48 * 4))
	{
		x += moveSpeed;
	}

}