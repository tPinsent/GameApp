#pragma once
#include "gameobject.h"
class Bullet :
	public GameObject
{
public:
	Bullet(void);
	~Bullet(void);

		
	void Initialize(Vector2 posInit);
  void Update(float dt);
  void Draw(SDL_Renderer *renderer, float dt);

protected:
	Vector2 pos;
};

