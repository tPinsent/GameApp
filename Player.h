#pragma once
#include "gameobject.h"
class Player :
	public GameObject
{
public:
	Player(void);
	~Player(void);
	
	void Initialize();
  void Update(float dt);
  void Draw(SDL_Renderer *renderer, float dt);

protected: 
	Vector2 pos;
  Vector2 endPointOffset;
  float speed;
  float rotationSpeed;
};

