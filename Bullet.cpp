#include "Bullet.h"
#include "MathUtils.h"
#include <SDL.h>
#include <stdio.h>
#include "Player.h"
#include <math.h>

//defualt constructor, empty
Bullet::Bullet(){}
//destructor, empty
Bullet::~Bullet(void){}
/**
 * \fn void Bullet::Bullet()
 * \brief gives the bullet a player to get location information from when initalizeing
 */
Bullet::Bullet(Player* player)
{
	_player = player;
}



/**
 * \fn void Bullet::Initialize()
 * \brief initializes the bullet variables
 */
void Bullet::Initialize()
{
	pos = _player->getCenter();
	direction = _player->getFront();
	speed = 10;
}

/**
 * \fn void Bullet::Update(float)
 * \brief updates the bullet's position baed on speed and direction
 * wraps if out of bounds
 */
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

/**
 * \fn void Bullet::Draw(SDL_Renderer, float)
 * \brief draws the bullet on the screen as a small circle
 * \param SDL_Renderer a renderer to be used to draw the bullet to
 * \param dt delta time since last call
 */
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

//returns the bullets current position
Vector2 Bullet::getPosition(){return pos;}