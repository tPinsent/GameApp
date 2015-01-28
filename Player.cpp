#include "Player.h"
#include <SDL.h>
#include "MathUtils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Bullet.h"

Player::Player(void)
{
}


Player::~Player(void)
{
}

void Player::Initialize(){

	a=0.0f;
  rotationSpeed = 0.0f;
	velocity=0.0f;
	ship.center.x=320.0f;
	ship.center.y=320.0f;
	ship.front.x=0.0f;
	ship.front.y=-20.0f;
	ship.left.x=-10.0f;
	ship.left.y=5.0f;
	ship.right.x=10.0f;
	ship.right.y=5.0f;
	speed = 50;
	_bullet = NULL;
}
  
void Player::Update(float dt){
	SDL_Event evt;
  SDL_PollEvent(&evt);

  // Check for user input.
  if (evt.type == SDL_KEYDOWN)
  {
    SDL_KeyboardEvent &keyboardEvt = evt.key;
    SDL_Keycode &keyCode = keyboardEvt.keysym.sym;
    switch (keyCode)
    {
    case SDLK_UP: //up arrow key
			CY += ((front.y) * speed) *dt;
			CX += ((front.x) * speed) *dt;
			break;
		case SDLK_RIGHT: //right arrow key
			rotationSpeed = (300*dt);
			break;
		case SDLK_LEFT: //left arrow key
			rotationSpeed = (-300*dt);
			break;
		case SDLK_SPACE:
			_bullet = new Bullet(this);
			_bullet->Initialize();
			break;
    default:
      break;
    }
  }
	else
	{
		(rotationSpeed > 0 && rotationSpeed != 0) ?
			rotationSpeed-=(10*dt) : rotationSpeed += (10*dt);
	}

	//out of bounds checking
	if(CX<0)
		CX = 640;
	if(CX > 640)
		CX = 0;
	if(CY < 0)
		CY=640;
	if(CY > 640)
		CY=0;
	if(_bullet != NULL)
		_bullet->Update(dt);
}

void Player::Draw(SDL_Renderer *renderer, float dt){
	 // Set the draw colour for our point.
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

  // Draw the point.
  //SDL_RenderDrawPoint(renderer, posX, posY);

  static float rotationDegrees = 10.0f;
  rotationDegrees += (rotationSpeed);
  rotationDegrees += (rotationDegrees >= 360.0f ? -360.0f : 0);

  float rotationRadians = MathUtils::ToRadians(rotationDegrees);
	
	//calcualte the position of the front point for the player
	front.x = FX * cosf(rotationRadians) + FY * sinf(rotationRadians);
	front.y = FX * sinf(rotationRadians) - FY * cosf(rotationRadians);

	//calcualte the position of the left point for the player
	left.x = LX * cosf(rotationRadians) + LY * sinf(rotationRadians);
  left.y = LX * sinf(rotationRadians) - LY * cosf(rotationRadians);
  

	//calculate the poistion of the right point for the player
  right.x = RX * cosf(rotationRadians) + RY * sinf(rotationRadians);
  right.y = RX * sinf(rotationRadians) - RY * cosf(rotationRadians);

	//draw the center dot for the player, testing only
	SDL_RenderDrawPoint(renderer,CX,CY);

	//draw the triangle points calculated earlier
	SDL_RenderDrawLine(renderer,CX+front.x,CY+front.y,CX+left.x,CY+left.y);
	SDL_RenderDrawLine(renderer,CX+front.x,CY+front.y,CX+right.x,CY+right.y);
	SDL_RenderDrawLine(renderer,CX+right.x,CY+right.y,CX+left.x,CY+left.y);
	
	if(_bullet != NULL)
		_bullet->Draw(renderer,dt);
}

void Player::DestroyBullet(){
	delete _bullet;
	_bullet = NULL;
}


Vector2 Player::getCenter(){return ship.center;}
Vector2 Player::getFront(){return front;}
Vector2 Player::getBulletPos()
{
	if(_bullet != NULL)
		return _bullet->getPosition();
	Vector2 temp = {1000,1000};
	return temp;
}