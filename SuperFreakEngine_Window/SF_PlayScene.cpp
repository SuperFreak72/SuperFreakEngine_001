#include "SF_PlayScene.h"
#include "SF_GameObject.h"
#include "SF_Player.h"
#include "SF_Transform.h"
#include "SF_SpriteRenderer.h"
#include "SF_Input.h"
#include "SF_SceneManager.h"
#include "SF_Object.h"
#include "SF_Resources.h"
#include "SF_HomeScene.h"
#include "SF_VillageScene.h"


namespace SF {
	PlayScene::PlayScene() { }
	PlayScene::~PlayScene() { }

	void PlayScene::Initialize() {
		bg = Object::Instantiate<Player>
			(enums::eLayerType::BackGround, Vector2(0.0f, 0.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

		Graphics::Texture* bg = Resources::Find<Graphics::Texture>(L"BG");
		sr->SetTexture(bg);
		Scene::Initialize();
	}
	void PlayScene::Update(){
		Scene::Update();
	}
	void PlayScene::LateUpdate() {
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"VillageScene");
		}
	}

	void PlayScene::Render(HDC hdc) {
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter() {
	}
	void PlayScene::OnExit() {
	}
}
