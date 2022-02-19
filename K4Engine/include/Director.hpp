#pragma once

#include "Singleton.hpp"
#include "Scene.hpp"
#include "Input.hpp"

namespace K4{
	class Director : public Singleton<Director>{
		friend class Singleton<Director>;
	private:
		Scene* _scene;
		Scene* _nextScene;
		bool _needRun;
		SDL_Window* _window;

		Director();
		virtual ~Director();

		void MainLoop();
	public:
		static bool ChangeScene(Scene *scene);
		static Scene* CurrentScene();

		static bool Init(int width = 800, int height = 600);
		static bool Run(Scene *scene);
		static void Finish();
	};
}
