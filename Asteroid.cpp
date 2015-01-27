#include "Asteroid.h"
#include "MathUtils.h"
#include <SDL.h>
#include <stdlib.h>
#include <math.h>

Asteroid::Asteroid(void)
{
}


Asteroid::~Asteroid(void)
{
}

void Asteroid::Initialize()
{
	spawn = rand() %4;
	if(spawn == 0) //spawn on top
	{
		pos.x = rand() % 600;
		pos.y = rand() %20;
		changeX=15;
		changeY=0;
	}
	else if(spawn == 1)//spawn on right
	{
		pos.x = rand() %20 + 620;
		pos.y = rand() % 600;
		changeX=40;
		changeY=15;
	}
	else if(spawn == 2) //spawn on bottem
	{
		pos.x = rand() % 600;
		pos.y = rand() % 20 + 620;
		changeX=25;
		changeY=40;
	}
	else if(spawn == 3)//spawn on left
	{
		pos.x = rand() % 20;
		pos.y = rand() % 600;
		changeX=-40;
		changeY=25;
	}
	
	radius = rand() %25 +10;
	float rotationDegrees = 10.0f;
	isAlive = true;

}


void Asteroid::Update(float dt)
{
	pos.x += ((rand() %40) - changeX) * dt;
	pos.y += ((rand() %40) - changeY) * dt;
	if(pos.x<0)
		pos.x = 640;
	if(pos.x > 640)
		pos.x = 0;
	if(pos.y < 0)
		pos.y=640;
	if(pos.y > 640)
		pos.y-0;
}

void Asteroid::Draw(SDL_Renderer *renderer, float dt)
{
	static float rotationDegrees = 10.0f;
	rotationDegrees += (rotationDegrees >= 360.0f ? -360.0f : 0);
	float rotationRadians = MathUtils::ToRadians(rotationDegrees);

	float radians;

	for(int i=0; i<360; i++)
	{
		radians = MathUtils::ToRadians(i);
		Vector2 point = 
		{
			radius * cosf(radians) + radius * sinf(radians),
			radius * sinf(radians) - radius * cosf(radians)
		};

		SDL_RenderDrawPoint(renderer,pos.x+point.x,pos.y+point.y);
	}

}