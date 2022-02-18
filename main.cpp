#include <iostream>
#include <SDL2/SDL.h>
using namespace std;
// using namespace K4;

int main()
{
	bool quit = false;
	Uint32 lastFrameStart = 0;
	Uint32 currentTick;
	int rightClicked = 0;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window = SDL_CreateWindow("42RL",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	while (!quit)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				quit = true;
		}
	}
	return 0;
}
