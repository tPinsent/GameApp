#include "GameObject.h"
#include "GameEngine.h"
#include <SDL.h>
#include <math.h>
#include "MathUtils.h"
#include "Player.h"

GameEngine::GameEngine()
{

}

GameEngine::~GameEngine()
{

}

void GameEngine::Initialize()
{
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

  window = SDL_CreateWindow("CST8237 Lab",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    640, 640,
    SDL_WINDOW_SHOWN);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // Using the default member-wise initializer for our new struct.
 
	player = new Player();
	player->Initialize();
	oldTime = SDL_GetTicks();
  currentTime = oldTime;
}

void GameEngine::Shutdown()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

void GameEngine::Update()
{
	oldTime = currentTime;
  currentTime = SDL_GetTicks();
  deltaTime = (currentTime - oldTime) / 1000;
  player->Update(deltaTime);
}

void GameEngine::Draw()
{
  // Set the draw colour for screen clearing.
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  // Clear the renderer with the current draw colour.
  SDL_RenderClear(renderer);
	
	player->Draw(renderer,deltaTime);
 
  // Present what is in our renderer to our window.
  SDL_RenderPresent(renderer);
}