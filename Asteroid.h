#pragma once
/**
 * \class Asteroidt.h
 * \brief used to create and manage an asteroid 
 * \author Alec Pinsent
 * \date January 29, 2015
 */

#include "gameobject.h"
class Asteroid :
	public GameObject
{
public:
	Asteroid(void);
	~Asteroid(void);

/**
 * \fn void Asteroid::Initialize()
 * \brief initializes all the values for the asteroid
 * randomizes radius, x position, y position, and side of the screen to spawn on
 */
	void Initialize();

/**
 * \fn void Asteroid::Update(float dt)
 * \brief updates the asteroid potion bsaed on random changes to the X and Y axis
 * \param dt: the delta time since last call
 */
  void Update(float dt);
/**
 * \fn void Asteroid::Draw(SDL_Renderer, float)
 * \brief canculates and draws the circles around the position that represent the asteroid
 * \param SDL_Renderer the renderer for the window
 * \param dt the delta time since last call
 */
  void Draw(SDL_Renderer *renderer, float dt);

	//gets radius
	float getRadius();
	//gets position
	Vector2 getPosition();

protected:
	Vector2 pos;
	float radius;
	int spawn;
	int changeX;
	int changeY;
};

