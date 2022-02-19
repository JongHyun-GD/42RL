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

		Director();
		virtual ~Director();

		void MainLoop();
	public:
		static bool ChangeScene(Scene *scene);
		static Scene* CurrentScene();

		static bool Run(Scene *scene);
		static void Finish();
	};
}
