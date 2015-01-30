#pragma once 

/**
 * \class GameObject.h
 * \brief An abstract class that represents a single object that can  
 * be placed and manipulated in the world.
 * \author Justin Wilkinson
 * \date January 29, 2015
 */


#include "MathUtils.h"

struct SDL_Renderer;

class GameObject
{
public:
	//used to initialize the given object
  virtual void Initialize() = 0;
  //used to update the given object
  virtual void Update(float dt) = 0;
	//used to draw the given object
  virtual void Draw(SDL_Renderer *renderer, float dt) = 0;

  ~GameObject();

protected:
  GameObject();

  Transform _transform;
};