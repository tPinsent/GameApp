#pragma once

#include "GameEngine.h"

#define MAX_AST 15 //basically.... diffuculty(max asteroids)

class Game: public GameEngine
{
  friend class GameEngine;

protected:
  Game();

  void InitializeImpl();
  void UpdateImpl(float dt);
  void DrawImpl(SDL_Renderer *renderer, float dt);
	float getScore();

  Player *_player;
	Asteroid *_asteroid[MAX_AST];
  // Using the default member-wise initializer for our new struct.
  Vector2 pos;
  Vector2 endPointOffset;
  float speed;
  float rotationSpeed;
	float score;
};