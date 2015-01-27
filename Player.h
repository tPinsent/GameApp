#pragma once
#include "gameobject.h"

#define CX ship.center.x
#define CY ship.center.y
#define FX ship.front.x
#define FY ship.front.y
#define LX ship.left.x
#define LY ship.left.y
#define RX ship.right.x
#define RY ship.right.y


struct tri{
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
	
	void Initialize();
  void Update(float dt);
  void Draw(SDL_Renderer *renderer, float dt);
	float getDirection();

protected: 
	Vector2 front;
	Vector2 left;
	Vector2 right;
	tri ship;
	
  float speed;
  float rotationSpeed;
	float velocity;
	float a;
};

