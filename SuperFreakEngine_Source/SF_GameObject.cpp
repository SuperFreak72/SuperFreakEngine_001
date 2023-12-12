#include "SF_GameObject.h"
#include "SF_Input.h"
#include "SF_Time.h"
#include "SF_Transform.h"

namespace SF::object {
	void Destroy(GameObject* gameObject) {
		if (gameObject != nullptr)
			gameObject->death();
	}
}

namespace SF {
	GameObject::GameObject() 
	: mState(eState::Active) {
		mComponents.resize((UINT)enums::eComponentType::End);
		initializeTransform();
	}

	GameObject::~GameObject() {
		for (Component* comp : mComponents) {
			if (comp == nullptr)
				continue;

			delete comp;
			comp = nullptr;
		}
	}

	void SF::GameObject::Initialize() {
		for (Component* comp : mComponents) {
			if (comp == nullptr)
				continue;
			comp->Initialize();
		}
	}
	void GameObject::Update() {
		for (Component* comp : mComponents) {
			if (comp == nullptr)
				continue;
			comp->Update();
		}
	}

	void GameObject::LateUpdate() { 
		for (Component* comp : mComponents) {
			if (comp == nullptr)
				continue;
			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc) {
		for (Component* comp : mComponents) {
			if (comp == nullptr)
				continue;
			comp->Render(hdc);
		}
	}

	void GameObject::initializeTransform(){
		AddComponent<Transform>();
	}
}


