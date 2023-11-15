#include "SF_PlayScene.h"
#include "SF_GameObject.h"
#include "SF_Player.h"
#include "SF_Transform.h"
#include "SF_SpriteRenderer.h"


namespace SF {
	PlayScene::PlayScene() { }

	PlayScene::~PlayScene() { }

	void PlayScene::Initialize() {
		Player* pl = new Player();
		Transform* tr
			= pl->AddComponent<Transform>();
		tr->SetPos(800, 450);
		tr->SetName(L"TransformC");
		SpriteRenderer* sr
			= pl->AddComponent<SpriteRenderer>();
		sr->SetName(L"SpriteRendererC");

		AddGameObject(pl);
	}

	void PlayScene::Update(){
		Scene::Update();
	}

	void PlayScene::LateUpdate() {
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC hdc) {
		Scene::Render(hdc);
	}
}
