#include "Director.hpp"
#include "SDL2/SDL.h"
#include <chrono>

namespace K4{
	using namespace std::chrono;

	Director::Director()
		: _scene(nullptr), _needRun(true), _nextScene(nullptr), _window(nullptr) {
		SDL_Init(SDL_INIT_VIDEO);
	}

	Director::~Director(){
		if (_scene)
			delete _scene;
		if (_window)
			SDL_DestroyWindow(_window);

		SDL_Quit();
	}

	void Director::MainLoop(){
		float timeSinceStart = 0.f;
		SDL_Event event;
		
		_scene->StartAllObject();
		_scene->Start();
		while (_needRun && _scene){

			_scene->UpdateAllObject();
			_scene->Update();

			// TEST CODE
			Input::GetInstance()->UpdateKeyState(SDL_GetTicks());

			if (_nextScene){
				delete _scene;
				_scene = _nextScene;
				_nextScene = nullptr;

				_scene->StartAllObject();
				_scene->Start();
			}

			SDL_PollEvent(&event);
			if (event.type == SDL_QUIT)
				Finish();
		}
	}

	bool Director::ChangeScene(Scene *scene){
		auto pd = Director::GetInstance();
		if (pd->_nextScene)
			return false;
		pd->_nextScene = scene;
		return true;
	}

	Scene* Director::CurrentScene(){
		return Director::GetInstance()->_scene;
	}

	bool Director::Init(int width, int height){
		auto pd = Director::GetInstance();
		auto window = SDL_CreateWindow("42RL",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (!window)
			return false;
		pd->_window = window;
		return true;
	}

	bool Director::Run(Scene *scene){
		auto pd = Director::GetInstance();
		if (pd->_scene)
			return false;
		pd->_scene = scene;
		pd->MainLoop();
		return true;
	}

	void Director::Finish(){
		auto pd = Director::GetInstance();
		pd->_needRun = false;
	}
}
