#pragma once
#include "SF_Entity.h"
#include "SF_GameObject.h"
#include "SF_Layer.h"

namespace SF {
	class Scene : public Entity {
	public:
		Scene();
		~Scene();
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObject, const enums::eLayerType type);
		Layer* GetLayer(const enums::eLayerType type) {
			return mLayers[(UINT)type];
		}
	private:
		void createLayers();
	private:
		std::vector<Layer*> mLayers;
	};
}

