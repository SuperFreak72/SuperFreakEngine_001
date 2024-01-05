#include "SF_CrossroadScene.h"
#include "SF_GameObject.h"
#include "SF_Player.h"
#include "SF_Input.h"
#include "SF_Transform.h"
#include "SF_SpriteRenderer.h"
#include "SF_SceneManager.h"
#include "SF_Object.h"
#include "SF_Resources.h"
#include "SF_PlayerScript.h"
#include "SF_Camera.h"
#include "SF_Renderer.h"
#include "SF_Animator.h"
#include "SF_BoxCollider2D.h"
#include "SF_CollisionManager.h"
#include "SF_BackGround.h"

namespace SF{
	CrossroadScene::CrossroadScene() {}
	CrossroadScene::~CrossroadScene() {}

	void CrossroadScene::Initialize() {
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Player, true);

		bg = Object::Instantiate<BackGround>
			(enums::eLayerType::BackGround);
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		Graphics::Texture* bg = Resources::Find<Graphics::Texture>(L"Entrance");

		player = Object::Instantiate<Player>(enums::eLayerType::Player);
		player->AddComponent<PlayerScript>();
		BoxCollider2D* collider = player->AddComponent<BoxCollider2D>();
		collider->SetOffset(Vector2::Zero);
		collider->SetSize(Vector2(2.0f, 2.0f));

		sr->SetTexture(bg);
		sr->SetSize(Vector2(4.0f, 4.0f));

		Scene::Initialize();
	}
	void CrossroadScene::Update() {
		
		Scene::Update();
	}

	void CrossroadScene::LateUpdate() {
		Scene::LateUpdate();
	}

	void CrossroadScene::Render(HDC hdc) {
		Scene::Render(hdc);
	}

	void CrossroadScene::OnEnter() {
		Renderer::mainCamera = cameraComp;
		cameraComp->SetTarget(player);

		player->GetComponent<Transform>()->SetPosition(Vector2(2440.0f, 3892.0f));
		player->GetComponent<Transform>()->SetScale(Vector2(4.0f, 4.0f));
	}

	void CrossroadScene::OnExit() {
		
	}
}