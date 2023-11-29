#include "SF_VillageScene.h"
#include "SF_HomeScene.h"
#include "SF_PlayScene.h"

#include "SF_GameObject.h"
#include "SF_Player.h"
#include "SF_Transform.h"
#include "SF_SpriteRenderer.h"
#include "SF_Input.h"
#include "SF_SceneManager.h"
#include "SF_Object.h"



namespace SF {
	VillageScene::VillageScene() { }
	VillageScene::~VillageScene() { }

	void VillageScene::Initialize() {
		/*bg = Object::Instantiate<Player>
			(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->ImageLoad(L"C:\\Users\\pokej\\Desktop\\WinAPIProject\\Editer_Window\\\Resources\\VillageEnvironment.png");
		*/
		Scene::Initialize();
	}
	void VillageScene::Update() {
		Scene::Update();
	}
	void VillageScene::LateUpdate() {
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void VillageScene::Render(HDC hdc) {
		Scene::Render(hdc);
		wchar_t str[50] = L"Village Scene";
		TextOut(hdc, 0, 0, str, 13);
	}

	void VillageScene::OnEnter() { }
	void VillageScene::OnExit() { }
}
