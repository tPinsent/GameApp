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
  score=610;
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

	_player->Update(dt);

	for(int i = 0; i<MAX_AST; i++)
	{
		//bullet
		float distB = sqrtf(powf(_player->getBulletPos().x-_asteroid[i]->getPosition().x,2) + powf(_player->getBulletPos().y-_asteroid[i]->getPosition().y,2)); //calculate distance between bullet and asteroid
		if(_asteroid[i]->getRadius() >= distB-20)
		{
			score+=100;
			_player->DestroyBullet();
			delete _asteroid[i];
			_asteroid[i] = new Asteroid();
			_asteroid[i]->Initialize();
		}

		//ship
		float distS = sqrtf(powf(_player->getCenter().x-_asteroid[i]->getPosition().x,2) + powf(_player->getCenter().y-_asteroid[i]->getPosition().y,2)); //calculate distance between bullet and asteroid
		if(_asteroid[i]->getRadius() >= distS-20)
		{
			score = 0;
			_player->Initialize();
			for(int i=0;i<MAX_AST;i++){
				_asteroid[i] = new Asteroid();
				_asteroid[i]->Initialize();
			}
			
		}



	}

	for(int i=0;i<MAX_AST;i++)
		_asteroid[i]->Update(dt);

}

void Game::DrawImpl(SDL_Renderer *renderer, float dt)
{
 
  _player->Draw(renderer, dt);
	for(int i=0;i<MAX_AST;i++)
		_asteroid[i]->Draw(renderer,dt);


}

float Game::getScore(){return score;}