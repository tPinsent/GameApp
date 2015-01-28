#pragma once
#include "gameobject.h"
class Player;
class Bullet :
	public GameObject
{
public:
	Bullet(void);
	Bullet(Player* player);
	~Bullet(void);

	void Initialize();
  void Update(float dt);
  void Draw(SDL_Renderer *renderer, float dt);

	Vector2 getPosition();

protected:
	Player *_player;
	Vector2 pos;
	Vector2 direction;
	int speed;

};

