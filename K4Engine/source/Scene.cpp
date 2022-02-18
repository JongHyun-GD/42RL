#include "Scene.hpp"

namespace K4{
	using namespace std;

	Scene::Scene(){}
 
	Scene::~Scene(){
		for (auto it : _gameObjectList){
			if(it)
				delete it;
		}
		_gameObjectList.clear();
	}

	void Scene::StartAllObject(GameObject* obj){
		if (obj){
			obj->Start();
			for (auto it : obj->_children)
				StartAllObject(it);
		} else {
			for (auto it : _gameObjectList)
				StartAllObject(it);
		}
	}

	void Scene::UpdateAllObject(GameObject* obj){
		if (obj){
			obj->Update();
			for (auto it : obj->_children)
				UpdateAllObject(it);
		} else {
			for (auto it : _gameObjectList)
				UpdateAllObject(it);
		}
	}

	void Scene::AddObject(GameObject* obj){
		_gameObjectList.push_back(obj);
	}

	bool Scene::DestroyObject(GameObject* obj){
		bool found = (find(_gameObjectList.begin(), _gameObjectList.end(), obj) != _gameObjectList.end());
		if (found){
			_gameObjectList.remove(obj);
			return true;
		}
		return false;
	}
}