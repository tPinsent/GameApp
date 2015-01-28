#pragma once
#include "gameobject.h"
class Asteroid :
	public GameObject
{
public:
	Asteroid(void);
	~Asteroid(void);

	void Initialize();
  void Update(float dt);
  void Draw(SDL_Renderer *renderer, float dt);

	float getRadius();
	Vector2 getPosition();

protected:
	Vector2 pos;
	float radius;
	int spawn;
	int changeX;
	int changeY;
};

