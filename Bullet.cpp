#include "Bullet.h"
#include "MathUtils.h"
#include <SDL.h>
#include <stdio.h>
#include "Player.h"
#include <math.h>


Bullet::Bullet(){}
Bullet::Bullet(Player* player)
{
	_player = player;
}


Bullet::~Bullet(void)
{
}

void Bullet::Initialize()
{
	pos = _player->getCenter();
	direction = _player->getFront();
	speed = 10;
	printf("shooting\n");
}


void Bullet::Update(float dt)
{
	pos.x += (direction.x * speed) * dt;
	pos.y += (direction.y * speed) * dt;
		if(pos.x<0)
		pos.x = 640;
	if(pos.x > 640)
		pos.x = 0;
	if(pos.y < 0)
		pos.y=640;
	if(pos.y > 640)
		pos.y=0;
}

void Bullet::Draw(SDL_Renderer *renderer, float dt)
{
	SDL_RenderDrawPoint(renderer, pos.x,pos.y);
	float radians;
	float radius = 2.0f;
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


Vector2 Bullet::getPosition(){return pos;}