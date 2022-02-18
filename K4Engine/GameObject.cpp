#include "GameObject.hpp"
#include "Director.hpp"

namespace K4{
	GameObject::GameObject() : parent(nullptr){}
	GameObject::~GameObject() {
		for(auto it : _children)
			if (it) delete it;
	}

	void GameObject::Render(){
		
	}

	void GameObject::Destroy(){
		if (parent){
			parent->_children.remove(this);
			parent = nullptr;
			delete this;
		}
		else{
			Director::CurrentScene()->DestroyObject(this);
			delete this;
		}
	}

	void GameObject::AddChild(GameObject *obj){
		_children.push_back(obj);
		obj->parent = this;
	}
}