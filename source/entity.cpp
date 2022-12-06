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

Entity::Entity()
{

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


void Entity::changeX(float change)
{
	x = change;
}

void Entity::changeY(float change)
{
	y = change;
}