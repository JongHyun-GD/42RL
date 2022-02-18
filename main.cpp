#include <iostream>
#include <SDL2/SDL.h>
#include "Input.hpp"
using namespace std;
using namespace K4;
#define FPS 1

#include <ObjectPool.hpp>
#include <MemoryPool.hpp>

struct A {
	int i, j, k;
};

int main()
{
	A *a = (A *)MemoryPool::get(sizeof(A));
	OPcreate(A, 10);
	A &aa = OPget(A);
	OPput(A, &aa);
	OPdestroy(A);

	/*
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
	*/
	return 0;
}
