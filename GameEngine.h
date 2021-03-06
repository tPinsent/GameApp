#pragma once // Preprocessor directive to ensure that this header will only be included once. -- Generally used on Windows

/**
 * \class GameEngine.h
 * \brief base game engine, used to drive the game loop
 * \author Alec Pinsent
 * \date January 29, 2015
 */


#include "MathUtils.h"
#include "Player.h"
#include "Timer.h"
#include "Asteroid.h"
#include "Bullet.h"

// Forward declaring our renderer and window.
// Because we're using them as pointers, we don't need to know their size
// at compile time to define this class.
struct SDL_Renderer;
struct SDL_Window;

class GameEngine
{
public:
  static GameEngine* CreateInstance();

  void Initialize();
  void Shutdown();

  void Update();
  void Draw();

  ~GameEngine();

protected:
  GameEngine();


  virtual void InitializeImpl() = 0;
  virtual void UpdateImpl(float dt) = 0;
  virtual void DrawImpl(SDL_Renderer *renderer, float dt) = 0;
  static GameEngine *_instance;

  SDL_Window *_window;
  SDL_Renderer *_renderer;
  Timer _engineTimer;
	

  float _oldTime, _currentTime, _deltaTime;
	int score;
};