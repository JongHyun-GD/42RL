#include <iostream>
#include <SDL2/SDL.h>
#include "Input.hpp"
#include "Director.hpp"
#include "HelloWorld.hpp"
using namespace std;
using namespace K4;

struct A {
	int i, j, k;
};

int main()
{
	bool quit = false;
	Uint32 lastFrameStart = 0;
	Uint32 currentTick;
	int rightClicked = 0;

	Director* director = Director::GetInstance();
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window = SDL_CreateWindow("42RL",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	Scene *scene = new HelloWorld;
	director->Run(scene);
	return 0;
}
