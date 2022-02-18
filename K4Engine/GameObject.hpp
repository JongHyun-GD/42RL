#pragma once

#include <list>
#include "Transform.hpp"

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
		virtual void Render();
	public:
		void Destroy();
		void AddChild(GameObject *obj);

		GameObject();
		virtual ~GameObject();
	};
}
