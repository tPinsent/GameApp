#pragma once
/**
 * \class Game.h
 * \brief An class that manages the main game loop
 * \author Alec Pinsent
 * \date January 29, 2015
 */

#include "GameEngine.h"

#define MAX_AST 15 //basically.... diffuculty(max asteroids)

class Game: public GameEngine
{
  friend class GameEngine;

protected:
  Game();

/**
 * \fn void Game::InitializeImpl()
 * \brief implementation of the main initalizer for the program, initalizes everything that will be used later on
 */
  void InitializeImpl();

/**
 * \fn void Game::UpdateImpl (float dt)
 * \brief called repeatedly to update all aspects of the game
 * \param dt The time in fractions of a second since the last pass.
 */
  void UpdateImpl(float dt);
  
/**
 * \fn void GameObject::Draw(SDL_Renderer *renderer, float dt)
 * \brief A virtual function that we’ll use as to define how our 
 * object is drawn to the screen.
 * \param renderer The SDL renderer used to draw the object.
 * \param dt The time in fractions of a second since the last pass.
 */
	void DrawImpl(SDL_Renderer *renderer, float dt);
	
	//pointer to the player object used to manage and control the player
  Player *_player;

	//array of asteroid pointers, used to manage and control the asteroids.
	Asteroid *_asteroid[MAX_AST];

	
};