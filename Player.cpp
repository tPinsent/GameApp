#include "Player.h"
#include <SDL.h>
#include "MathUtils.h"
#include <math.h>
#include <stdio.h>

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
    case SDLK_UP:
      a = atan2(CY-FY, CX-FX);
			speed += 30;
			break;
		case SDLK_RIGHT:
			rotationSpeed = (300*dt);
			break;
		case SDLK_LEFT:
			rotationSpeed = (-300*dt);
			break;
    default:
      break;
    }
  }
	else
	{
		if(speed > 0 )
			speed -= 1;
		if(speed < 0)
			speed = 0;
		(rotationSpeed > 0 && rotationSpeed != 0) ?
			rotationSpeed-=(10*dt) : rotationSpeed += (10*dt);
	}
	CX += (float) (cosf(a) * speed) * dt;
	CY += (float) (sinf(a) * speed) * dt; 
	if(CX<0)
		CX = 640;
	if(CX > 640)
		CX = 0;
	if(CY < 0)
		CY=640;
	if(CY > 640)
		CY-0;
	
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

	//draw the center dot for the player
	SDL_RenderDrawPoint(renderer,CX,CY);

	//draw the triangle points calculated earlier
	SDL_RenderDrawLine(renderer,CX+front.x,CY+front.y,CX+left.x,CY+left.y);
	SDL_RenderDrawLine(renderer,CX+front.x,CY+front.y,CX+right.x,CY+right.y);
	SDL_RenderDrawLine(renderer,CX+right.x,CY+right.y,CX+left.x,CY+left.y);
	

}

float Player::getDirection()
{
	return (CY-front.y) / (CX - front.x);
}