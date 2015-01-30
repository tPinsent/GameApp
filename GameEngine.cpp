#include "GameEngine.h"
#include <SDL.h>
#include "MathUtils.h"
#include <stdio.h>

GameEngine::GameEngine()
{

}

GameEngine::~GameEngine()
{

}
/**
 * \fn void GameEngine::Initialize()
 * \breif initialzies the game engine, window renderer and then calls the games init
 */
void GameEngine::Initialize()
{
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

  _window = SDL_CreateWindow("CST8237 Lab | score: 0",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    640, 640,
    SDL_WINDOW_SHOWN);

  _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

  InitializeImpl();
	
  /* Get the time at the beginning of our game loop so that we can track the
  * elapsed difference. */
  _engineTimer.Start();
}

/**
 * \fn void GameEngine::Shutdown()
 * \breif destroys the renderer and window as well as stoping the timer
 */
void GameEngine::Shutdown()
{
  _engineTimer.Stop();

  SDL_DestroyRenderer(_renderer);
  SDL_DestroyWindow(_window);
}

/**
 * \fn void GameEngine::Update()
 * \breif runs all updates for the program, as well as updating the window title
 */
void GameEngine::Update()
{
  // Calculating the time difference since our last loop.
  _engineTimer.Update();

  UpdateImpl(_engineTimer.GetDeltaTime());
	char* windowText = new char[100];
	sprintf(windowText,"CST8237 lab | score: %d\n",score);
	SDL_SetWindowTitle(_window,windowText); 
}

/**
 * \fn void GameEngine::Draw()
 * \breif clears the renderer, draws the game to it, then presents it
 */
void GameEngine::Draw()
{
  // Set the draw colour for screen clearing.
  SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);

  // Clear the renderer with the current draw colour.
  SDL_RenderClear(_renderer);

  DrawImpl(_renderer, _engineTimer.GetDeltaTime());
	
  // Present what is in our renderer to our window.
  SDL_RenderPresent(_renderer);
}