#pragma once

#include "entity.h"
#include "windowRender.h"

void renderFloor(RenderWindow& window)
{
	SDL_Texture* floorTex = window.loadTexture("res/gfx/floor.png");

	Entity floor0(0, 720 - (48 * 4), floorTex);
	Entity floor1(48 * 4, 720 - (48 * 4), floorTex);
	Entity floor2(48 * 4 * 2, 720 - (48 * 4), floorTex);
	Entity floor3(48 * 4 * 3, 720 - (48 * 4), floorTex);
	Entity floor4(48 * 4 * 4, 720 - (48 * 4), floorTex);
	Entity floor5(48 * 4 * 5, 720 - (48 * 4), floorTex);
	Entity floor6(48 * 4 * 6, 720 - (48 * 4), floorTex);

	window.render(floor0);
	window.render(floor1);
	window.render(floor2);
	window.render(floor3);
	window.render(floor4);
	window.render(floor5);
	window.render(floor6);
	
}