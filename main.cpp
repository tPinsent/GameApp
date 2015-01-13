#include <iostream>
#include <SDL.h>

using namespace std;

int main(int argc, char ** argv){
	//init SDL
	SDL_Init(SDL_INIT_VIDEO);

	//create the window
	SDL_Window *window = SDL_CreateWindow("TestWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, SDL_WINDOW_SHOWN);

	//init renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

	int posX = 100, posY = 100;
	while(true){
		SDL_Event evt;
		SDL_PollEvent(&evt);
		if(posY ==640){
			SDL_SetRenderDrawColor(renderer,255,255,255,255);
			SDL_RenderClear(renderer);
		}
		//set the draw colour or our point.
		SDL_SetRenderDrawColor(renderer,0,0,0,0);
		SDL_RenderDrawPoint(renderer,posX,posY);
		SDL_RenderPresent(renderer);

		posY = (posY < 640) ? posY +1 : 100;
	}


	//cleanup time
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return 0;
}