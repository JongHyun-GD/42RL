#include <iostream>
#include <SDL2/SDL.h>
#include "Input.hpp"
using namespace std;
using namespace K4;
#define FPS 1

int main()
{
	bool quit = false;
	Uint32 lastFrameStart = 0;
	Uint32 currentTick;
	int rightClicked = 0;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);
	while (!quit)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (Input::GetKeyDown(KEY_W) || Input::GetKeyDown(KEY_UP))
				cout << "Up pressed" << endl;
			if (Input::GetMultiKeyDown(KEY_LCTRL, KEY_W))
				cout << "ctrl + up pressed" << endl;
		}
	}
	return 0;
}
