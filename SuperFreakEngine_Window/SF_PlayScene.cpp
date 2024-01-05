#include "SF_PlayScene.h"
#include "SF_GameObject.h"
#include "SF_Player.h"
#include "SF_Monster.h"
#include "SF_Input.h"
#include "SF_Transform.h"
#include "SF_SpriteRenderer.h"
#include "SF_SceneManager.h"
#include "SF_Object.h"
#include "SF_Resources.h"
#include "SF_PlayerScript.h"
#include "SF_MonScript.h"
#include "SF_Camera.h"
#include "SF_Renderer.h"
#include "SF_Animator.h"
#include "SF_BoxCollider2D.h"
#include "SF_CollisionManager.h"
#include "SF_BackGround.h"


namespace SF {
	PlayScene::PlayScene() { }
	PlayScene::~PlayScene() { }

	void PlayScene::Initialize() {
		//배경설정
		bg = Object::Instantiate<BackGround>
			(enums::eLayerType::BackGround);
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		Graphics::Texture* bg = Resources::Find<Graphics::Texture>(L"BG");
		sr->SetTexture(bg);
		sr->SetSize(Vector2(4.0f, 4.0f));

		//예시 몬스터
		monster = Object::Instantiate<Monster>(enums::eLayerType::Monster);
		monster->AddComponent<MonScript>();
		monster->GetComponent<Transform>()->SetPosition(Vector2(100.0f,100.0f));

		//플레이어
		player = Object::Instantiate<Player>(enums::eLayerType::Player);
		player->AddComponent<PlayerScript>();
		player->GetComponent<Transform>()->SetPosition(Vector2(1000.0f, 1000.0f));
		player->GetComponent<Transform>()->SetScale(Vector2(4.0f, 4.0f));

		//카메라
		camera = Object::Instantiate<GameObject>(enums::eLayerType::Particle, Vector2(0.0f, 0.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		Renderer::mainCamera = cameraComp;
		cameraComp->SetTarget(player);
		
		Scene::Initialize();
	}

	void PlayScene::Update() {
		Vector2 pPos = player->GetComponent<Transform>()->GetPosition();
		if (pPos.x > 1248.0f && pPos.y < 50.0f && pPos.x < 1488.0f)
			SceneManager::LoadScene(L"CrossroadScene");
		else
			Scene::Update();
	}

	void PlayScene::LateUpdate() {
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC hdc) {
		Scene::Render(hdc);
	}

	void PlayScene::OnEnter() {
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
	}
	void PlayScene::OnExit() {
		
	}
}
