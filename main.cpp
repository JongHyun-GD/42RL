#include <iostream>
#include <SDL2/SDL.h>
using namespace std;
// using namespace K4;

#include <ObjectPool.hpp>
#include <MemoryPool.hpp>

struct A {
	int i, j, k;
};

int main()
{
	MemoryPool::GetInstance();

	A *a = (A *)MemoryPool::get(sizeof(A));
	MemoryPool::put(a);

	MemoryPool::DestroyInstance();

	ObjectPool<A>::GetInstance();

	A &r = ObjectPool<A>::get();
	ObjectPool<A>::put(&r);

	ObjectPool<A>::DestroyInstance();

	/*
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
	*/
	return 0;
}
