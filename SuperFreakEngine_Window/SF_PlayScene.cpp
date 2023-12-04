#include "SF_PlayScene.h"
#include "SF_GameObject.h"
#include "SF_Player.h"
#include "SF_Transform.h"
#include "SF_SpriteRenderer.h"
#include "SF_Input.h"
#include "SF_SceneManager.h"
#include "SF_Object.h"
#include "SF_Resources.h"
#include "SF_PlayerScript.h"
#include "SF_Camera.h"
#include "SF_Renderer.h"
#include "SF_Animator.h"


namespace SF {
	PlayScene::PlayScene() { }
	PlayScene::~PlayScene() { }

	void PlayScene::Initialize() {
		bg = Object::Instantiate<Player>
			(enums::eLayerType::BackGround, Vector2(0.0f, 0.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

		Graphics::Texture* bg = Resources::Find<Graphics::Texture>(L"BG");
		
		sr->SetTexture(bg);

		AnimationLoad();

		Scene::Initialize();
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
	void PlayScene::OnEnter() {
	}
	void PlayScene::OnExit() {
	}

	void PlayScene::AnimationLoad() {
		Player* player = Object::Instantiate<Player>(enums::eLayerType::Player);
		player->AddComponent<PlayerScript>();
		Graphics::Texture* PlayerWalkTex = Resources::Find<Graphics::Texture>(L"PlayerWalk");
		Graphics::Texture* PlayerIdleTex = Resources::Find<Graphics::Texture>(L"PlayerIdle");
		Graphics::Texture* PlayerGloveTex = Resources::Find<Graphics::Texture>(L"PlayerGlove");
		Animator* playerAnimator = player->AddComponent<Animator>();
		playerAnimator->CreateAnimation(L"LeftWalk", PlayerWalkTex,
			Vector2(0.0f, 0.0f), Vector2(35.0f, 43.0f), Vector2::Zero, 8, 0.07f);
		playerAnimator->CreateAnimation(L"RightWalk", PlayerWalkTex,
			Vector2(0.0f, 43.0f), Vector2(35.0f, 43.0f), Vector2::Zero, 8, 0.07f);
		playerAnimator->CreateAnimation(L"UpWalk", PlayerWalkTex,
			Vector2(0.0f, 86.0f), Vector2(35.0f, 43.0f), Vector2::Zero, 8, 0.07f);
		playerAnimator->CreateAnimation(L"DownWalk", PlayerWalkTex,
			Vector2(0.0f, 129.0f), Vector2(35.0f, 43.0f), Vector2::Zero, 8, 0.07f);
		playerAnimator->CreateAnimation(L"LeftRoll", PlayerWalkTex,
			Vector2(0.0f, 344.0f), Vector2(35.0f, 43.0f), Vector2::Zero, 8, 0.07f);
		playerAnimator->CreateAnimation(L"RightRoll", PlayerWalkTex,
			Vector2(0.0f, 387.0f), Vector2(35.0f, 43.0f), Vector2::Zero, 8, 0.07f);
		playerAnimator->CreateAnimation(L"UpRoll", PlayerWalkTex,
			Vector2(0.0f, 430.0f), Vector2(35.0f, 43.0f), Vector2::Zero, 8, 0.07f);
		playerAnimator->CreateAnimation(L"DownRoll", PlayerWalkTex,
			Vector2(0.0f, 473.0f), Vector2(35.0f, 43.0f), Vector2::Zero, 8, 0.07f);
		playerAnimator->CreateAnimation(L"Stand", PlayerWalkTex,
			Vector2(0.0f, 516.0f), Vector2(35.0f, 43.0f), Vector2::Zero, 1, 1.0f);

		playerAnimator->CreateAnimation(L"LeftIdle", PlayerIdleTex,
			Vector2(0.0f, 0.0f), Vector2(32.0f, 43.0f), Vector2::Zero, 10, 0.05f);
		playerAnimator->CreateAnimation(L"RightIdle", PlayerIdleTex,
			Vector2(0.0f, 43.0f), Vector2(32.0f, 43.0f), Vector2::Zero, 10, 0.05f);
		playerAnimator->CreateAnimation(L"UpIdle", PlayerIdleTex,
			Vector2(0.0f, 86.0f), Vector2(32.0f, 43.0f), Vector2::Zero, 10, 0.05f);
		playerAnimator->CreateAnimation(L"DownIdle", PlayerIdleTex,
			Vector2(0.0f, 129.0f), Vector2(32.0f, 43.0f), Vector2::Zero, 10, 0.05f);

		playerAnimator->CreateAnimation(L"LeftPunch", PlayerGloveTex,
			Vector2(0.0f, 0.0f), Vector2(44.0f, 43.0f), Vector2::Zero, 20, 0.04f);
		playerAnimator->CreateAnimation(L"RightPunch", PlayerGloveTex,
			Vector2(0.0f, 43.0f), Vector2(44.0f, 43.0f), Vector2::Zero, 20, 0.04f);
		playerAnimator->CreateAnimation(L"UpPunch", PlayerGloveTex,
			Vector2(0.0f, 86.0f), Vector2(44.0f, 43.0f), Vector2::Zero, 20, 0.04f);
		playerAnimator->CreateAnimation(L"DownPunch", PlayerGloveTex,
			Vector2(0.0f, 129.0f), Vector2(44.0f, 43.0f), Vector2::Zero, 20, 0.04f);

		playerAnimator->CreateAnimation(L"LeftLongPunch", PlayerGloveTex,
			Vector2(0.0f, 172.0f), Vector2(44.0f, 43.0f), Vector2::Zero, 16, 0.1f);
		playerAnimator->CreateAnimation(L"RightLongPunch", PlayerGloveTex,
			Vector2(0.0f, 215.0f), Vector2(44.0f, 43.0f), Vector2::Zero, 16, 0.1f);
		playerAnimator->CreateAnimation(L"UpLongPunch", PlayerGloveTex,
			Vector2(0.0f, 258.0f), Vector2(44.0f, 43.0f), Vector2::Zero, 16, 0.1f);
		playerAnimator->CreateAnimation(L"DownLongPunch", PlayerGloveTex,
			Vector2(0.0f, 301.0f), Vector2(44.0f, 43.0f), Vector2::Zero, 16, 0.1f);



		playerAnimator->PlayAnimation(L"DownIdle", true);
		player->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		player->GetComponent<Transform>()->SetScale(Vector2(3.0f, 3.0f));


	}
}
