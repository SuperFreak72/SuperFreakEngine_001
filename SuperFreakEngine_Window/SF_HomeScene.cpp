#include "SF_HomeScene.h"
#include "SF_GameObject.h"
#include "SF_Player.h"
#include "SF_Transform.h"
#include "SF_SpriteRenderer.h"
#include "SF_Input.h"
#include "SF_VillageScene.h"
#include "SF_SceneManager.h"
#include "SF_Object.h"


namespace SF {
	HomeScene::HomeScene() { }

	HomeScene::~HomeScene() { }

	void HomeScene::Initialize() {
		/*bg = Object::Instantiate<Player>
			(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->ImageLoad(L"C:\\Users\\pokej\\Desktop\\WinAPIProject\\Editer_Window\\VillageEnvironment.png");
		*/
		Scene::Initialize();
	}

	void HomeScene::Update() {
		Scene::Update();
	}

	void HomeScene::LateUpdate() {
		Scene::LateUpdate();
	}

	void HomeScene::Render(HDC hdc) {
		Scene::Render(hdc);
	}
	void HomeScene::OnEnter() { }
	void HomeScene::OnExit() { }
}