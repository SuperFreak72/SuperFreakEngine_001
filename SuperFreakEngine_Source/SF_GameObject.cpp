#include "SF_GameObject.h"
#include "SF_Input.h"
#include "SF_Time.h"

namespace SF {
	GameObject::GameObject() { }
	GameObject::~GameObject() {
		for (Component* comp : mComponents) {
			delete comp;
			comp = nullptr;
		}
	}

	void SF::GameObject::Initialize() {
		for (Component* comp : mComponents) {
			comp->Initialize();
		}
	}
	void GameObject::Update() {
		for (Component* comp : mComponents) {
			comp->Update();
		}
	}

	void GameObject::LateUpdate() { 
		for (Component* comp : mComponents) {
			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc) {
		for (Component* comp : mComponents) {
			comp->Render(hdc);
		}
	}
}


