#pragma once

#include <list>

namespace K4{
	class GameObject{
		friend class Scene;
	protected:
		GameObject *parent;
	private:
		std::list<GameObject*> _children;


	protected:
		virtual void Start() = 0;
		virtual void Update() = 0;
	public:
		void Destroy();
		void AddChild(GameObject *obj);

		GameObject();
		virtual ~GameObject();
	};
}
