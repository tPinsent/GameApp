#pragma once

/**
 * \class Player.h
 * \brief creates and manages a player that can be controled by the user
 * \author Alec Pinsent
 * \date January 29, 2015
 */


#include "gameobject.h"
// defines used to make dealwith with the ship variables... less writeing(#lazy)
#define CX ship.center.x
#define CY ship.center.y
#define FX ship.front.x
#define FY ship.front.y
#define LX ship.left.x
#define LY ship.left.y
#define RX ship.right.x
#define RY ship.right.y

//forward delcaration
class Bullet;

//stuct to contain and manage a triangle
struct tri {
	Vector2 front;
	Vector2 left;
	Vector2 right;
	Vector2 center;
};

class Player :
	public GameObject
{
public:
	Player(void);
	~Player(void);
	
/**
 * \fn void Player::Initialize()
 * \brief used to initalize local variables for the player
 */
	void Initialize();

/**
 * \fn void Player::Update(float dt)
 * \brief Update function implementation for the player, checks for input related to the player and bound restriction
 * \param dt The time in fractions of a second since the last pass.
 */
  void Update(float dt);

/**
 * \fn void Player::Draw(SDL_Renderer *renderer, float dt)
 * \brief used to draw the player on the screen
 * \param renderer The SDL renderer used to draw the object.
 * \param dt The time in fractions of a second since the last pass.
 */
  void Draw(SDL_Renderer *renderer, float dt);

/**
 * \fn void Player::DestroyBullet()
 * \brief used to destroy the bullet when a collision is detected
 */
	void DestroyBullet();
	//returns the front vector
	Vector2 getFront();
	//returns the center vector
	Vector2 getCenter();
	//returns the bullet vector
	Vector2 getBulletPos();


protected: 
	//pointer to manage the bullet
	Bullet *_bullet;
	//contains the current location on screen of the front of the ship
	Vector2 front;
	//contains the current location on screen of the left of the ship
	Vector2 left;
	//contains the current location on screen of the right of the ship
	Vector2 right;
	//ship variable
	tri ship;
	//contains the base speed the ship can travel
  float speed;
	//contians the base rotation speed of the ship
  float rotationSpeed;
};

