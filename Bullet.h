#pragma once
/**
 * \class Bullet.h
 * \brief a class that contains and manages a Bullet that the player can shoot.
 * \author Alec Pinsent
 * \date January 27, 2015
 */

#include "gameobject.h"
class Player;
class Bullet :
	public GameObject
{
public:
	Bullet(void);
	Bullet(Player* player);
	~Bullet(void);

/**
 * \fn void Bullet::Initialize()
 * \brief initializes the bullet variables
 */
	void Initialize();

/**
 * \fn void Bullet::Update(float)
 * \brief updates the bullet's position baed on speed and direction
 * wraps if out of bounds
 */
  void Update(float dt);

/**
 * \fn void Bullet::Draw(SDL_Renderer, float)
 * \brief draws the bullet on the screen as a small circle
 * \param SDL_Renderer a renderer to be used to draw the bullet to
 * \param dt delta time since last call
 */
  void Draw(SDL_Renderer *renderer, float dt);

	//returns bullets current position
	Vector2 getPosition();

protected:
	Player *_player;
	Vector2 pos;
	Vector2 direction;
	int speed;

};

