#include "Director.hpp"
#include "SDL2/SDL.h"
#include <chrono>

namespace K4{
	using namespace std::chrono;

	Director::Director(): _scene(nullptr), _needRun(true) {}
	Director::~Director(){
		if (_scene)
			delete _scene;
	}

	void Director::MainLoop(){
		float timeSinceStart = 0.f;
		int curTime = SDL_GetTicks();

		_scene->StartAllObject();
		_scene->Start();
		while (_needRun && _scene){

			_scene->UpdateAllObject();
			_scene->Update();

			int endTime = SDL_GetTicks();
			int deltaTime = endTime - curTime;
			curTime = endTime;

			// TEST CODE
			Input::GetInstance()->UpdateKeyState(endTime);

			if (_nextScene){
				delete _scene;
				_scene = _nextScene;
				_nextScene = nullptr;

				_scene->StartAllObject();
				_scene->Start();
			}
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
