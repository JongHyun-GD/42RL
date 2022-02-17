#pragma once

#include "GameObject.hpp"

namespace K4{
	class Scene
	{
	friend class Director;
	private:
		std::list<GameObject*> _gameObjectList;

		void StartAllObject(GameObject* obj = nullptr);
		void UpdateAllObject(GameObject* obj = nullptr);
	protected:
		virtual void Start() = 0;
		virtual void Update() = 0;
	public:
		Scene();
		virtual ~Scene();

		void AddObject(GameObject* obj);
		bool DestroyObject(GameObject* obj);
	};
}