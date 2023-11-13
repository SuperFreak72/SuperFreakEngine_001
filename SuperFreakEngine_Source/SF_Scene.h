#pragma once
#include "SF_Entity.h"
#include "SF_GameObject.h"

namespace SF {
	class Scene : public Entity {
	public:
		Scene();
		~Scene();
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);
	private:
		std::vector<GameObject*> mGameObjects;
	};
}

