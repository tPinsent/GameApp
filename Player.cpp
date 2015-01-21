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
	
	pos.x=200.0f;
	pos.y=200.0f;
  endPointOffset.x=10.0f;
	endPointOffset.y=0.0f;
  speed = 300.0f;
  rotationSpeed = 0.0f;

}
  
void Player::Update(float dt){
	SDL_Event evt;
  SDL_PollEvent(&evt);

  // Calculating the time difference since our last loop.
 

  // Check for user input.
  if (evt.type == SDL_KEYDOWN)
  {
    SDL_KeyboardEvent &keyboardEvt = evt.key;
    SDL_Keycode &keyCode = keyboardEvt.keysym.sym;
    switch (keyCode)
    {
    case SDLK_UP:
      pos.y -= (speed * dt);
      break;
    case SDLK_DOWN:
      pos.y += (speed * dt);
      break;
		case SDLK_RIGHT:
			rotationSpeed = (-300*dt);
			printf("%d\n",rotationSpeed);
			break;
		case SDLK_LEFT:
			rotationSpeed = (300*dt);
			printf("%d\n",rotationSpeed);
			break;
    default:
      break;
    }
  }

	(rotationSpeed > 0) ?
		rotationSpeed-=(10*dt) : rotationSpeed += (10*dt);
	
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

  Vector2 rotatedOffset =
  {
    endPointOffset.x * cosf(rotationRadians) + endPointOffset.y * sinf(rotationRadians),
    endPointOffset.x * sinf(rotationRadians) - endPointOffset.y * cosf(rotationRadians)
  };

  Vector2 transformedEndPoint = { pos.x + rotatedOffset.x, pos.y + rotatedOffset.y };

  SDL_RenderDrawLine(renderer, pos.x, pos.y, transformedEndPoint.x, transformedEndPoint.y);

}