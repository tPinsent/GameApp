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

protected:
	Vector2 pos;
	float radius;
	bool isAlive;
	int spawn;
	int changeX;
	int changeY;
};

