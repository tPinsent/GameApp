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

/**
 * \fn void Game::InitializeImpl()
 * \brief implementation of the main initalizer for the program, initalizes everything that will be used later on
 */
void Game::InitializeImpl()
{
  score=0;
	_player = new Player();
	_player->Initialize();
	for(int i=0;i<MAX_AST;i++){
		_asteroid[i] = new Asteroid();
		_asteroid[i]->Initialize();
	}
}

/**
 * \fn void Game::UpdateImpl (float dt)
 * \brief called repeatedly to update all aspects of the game
 * \param dt The time in fractions of a second since the last pass.
 */
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

/**
 * \fn void GameObject::Draw(SDL_Renderer *renderer, float dt)
 * \brief A virtual function that we’ll use as to define how our 
 * object is drawn to the screen.
 * \param renderer The SDL renderer used to draw the object.
 * \param dt The time in fractions of a second since the last pass.
 */
void Game::DrawImpl(SDL_Renderer *renderer, float dt)
{
 
  _player->Draw(renderer, dt);
	for(int i=0;i<MAX_AST;i++)
		_asteroid[i]->Draw(renderer,dt);


}