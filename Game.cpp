#include "Game.h"
#include <SDL.h>
#include <math.h>
#include <stdio.h>

// Initializing our static member pointer.
GameEngine* GameEngine::_instance = nullptr;

GameEngine* GameEngine::CreateInstance()
{
  if (_instance == nullptr)
  {
    _instance = new Game();
  }
  return _instance;
}

Game::Game() : GameEngine()
{

}

void Game::InitializeImpl()
{
  // Using the default member-wise initializer for our new struct.
	pos.x=100.0f;
	pos.y=100.0f;
	endPointOffset.x=10.0f;
	endPointOffset.y=0.0f;
  speed = 10.0f;
  rotationSpeed = 360.0f;
	_player = new Player();
	_player->Initialize();
	for(int i=0;i<MAX_AST;i++){
		_asteroid[i] = new Asteroid();
		_asteroid[i]->Initialize();
	}
}

void Game::UpdateImpl(float dt)
{
	printf("%d\n",_player->getDirection());
	_player->Update(dt);
	for(int i=0;i<MAX_AST;i++)
		_asteroid[i]->Update(dt);
}

void Game::DrawImpl(SDL_Renderer *renderer, float dt)
{
 
  _player->Draw(renderer, dt);
	for(int i=0;i<MAX_AST;i++)
		_asteroid[i]->Draw(renderer,dt);


}