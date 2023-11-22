#pragma once
#include "SF_Component.h"
#include "SF_GameObject.h"
#include "SF_Layer.h"
#include "SF_Scene.h"
#include "SF_SceneManager.h"
#include "SF_Transform.h"

namespace SF::Object {
	template <typename T>
	static T* Instantiate(SF::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(SF::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}
}
