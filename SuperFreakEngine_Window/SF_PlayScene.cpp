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
			(enums::eLayerType::BackGround);
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		Graphics::Texture* bg = Resources::Find<Graphics::Texture>(L"BG");
		
		sr->SetTexture(bg);
		sr->SetSize(Vector2(2.0f, 2.0f));

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
	void PlayScene::OnEnter() { }
	void PlayScene::OnExit() { }

	void PlayScene::AnimationLoad() {
		GameObject* camera = Object::Instantiate<GameObject>(enums::eLayerType::Player, Vector2(150.0f, 150.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		Renderer::mainCamera = cameraComp;


		player = Object::Instantiate<Player>(enums::eLayerType::Player);
		player->AddComponent<PlayerScript>();
		
		cameraComp->SetTarget(player);
		Animator* playerAnimator = player->AddComponent<Animator>();
		
		LoadAnimationIdle(playerAnimator);
		LoadAnimationWalk(playerAnimator);
		LoadAnimationRoll(playerAnimator);
		LoadAniamtionSwim(playerAnimator);
		LoadAnimationGrassIdle(playerAnimator);
		LoadAnimationGrassWalk(playerAnimator);
		LoadAnimationDeath(playerAnimator);
		LoadAnimationPendant(playerAnimator);
		LoadAnimationShortSword(playerAnimator);
		LoadAnimationShield(playerAnimator);
		LoadAnimationGloves(playerAnimator);
		
		playerAnimator->PlayAnimation(L"IdleDown", true);
		player->GetComponent<Transform>()->SetPosition(Vector2(0.0f, 0.0f));
		player->GetComponent<Transform>()->SetScale(Vector2(3.0f, 3.0f));


	}

	void PlayScene::LoadAnimationIdle(Animator* playerAnimator) {
		Graphics::Texture* PlayerMotionTex = Resources::Find<Graphics::Texture>(L"PlayerMotion");

		playerAnimator->CreateAnimation(L"IdleDown", PlayerMotionTex,
			Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 10, 0.07f);
		playerAnimator->CreateAnimation(L"IdleLeft", PlayerMotionTex,
			Vector2(0.0f, 128.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 10, 0.07f);
		playerAnimator->CreateAnimation(L"IdleRight", PlayerMotionTex,
			Vector2(0.0f, 256.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 10, 0.07f);
		playerAnimator->CreateAnimation(L"IdleUp", PlayerMotionTex,
			Vector2(0.0f, 384.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 10, 0.07f);
	}

	void PlayScene::LoadAnimationWalk(Animator* playerAnimator) {
		Graphics::Texture* PlayerMotionTex = Resources::Find<Graphics::Texture>(L"PlayerMotion");

		playerAnimator->CreateAnimation(L"WalkDown", PlayerMotionTex,
			Vector2(0.0f, 512.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.06f);
		playerAnimator->CreateAnimation(L"WalkLeft", PlayerMotionTex,
			Vector2(0.0f, 640.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.06f);
		playerAnimator->CreateAnimation(L"WalkRight", PlayerMotionTex,
			Vector2(0.0f, 768.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.06f);
		playerAnimator->CreateAnimation(L"WalkUp", PlayerMotionTex,
			Vector2(0.0f, 896.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.06f);
	}

	void PlayScene::LoadAnimationRoll(Animator* playerAnimator) {
		Graphics::Texture* PlayerMotionTex = Resources::Find<Graphics::Texture>(L"PlayerMotion");

		playerAnimator->CreateAnimation(L"RollDown", PlayerMotionTex,
			Vector2(0.0f, 1024.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.06f);
		playerAnimator->CreateAnimation(L"RollLeft", PlayerMotionTex,
			Vector2(0.0f, 1152.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.06f);
		playerAnimator->CreateAnimation(L"RollRight", PlayerMotionTex,
			Vector2(0.0f, 1280.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.06f);
		playerAnimator->CreateAnimation(L"RollUp", PlayerMotionTex,
			Vector2(0.0f, 1408.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.06f);
	}

	void PlayScene::LoadAniamtionSwim(Animator* playerAnimator) {
		Graphics::Texture* PlayerMotionTex = Resources::Find<Graphics::Texture>(L"PlayerMotion");

		playerAnimator->CreateAnimation(L"SwimDown", PlayerMotionTex,
			Vector2(0.0f, 1536.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 10, 0.06f);
		playerAnimator->CreateAnimation(L"RollLeft", PlayerMotionTex,
			Vector2(0.0f, 1664.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 10, 0.06f);
		playerAnimator->CreateAnimation(L"RollRight", PlayerMotionTex,
			Vector2(0.0f, 1792.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 10, 0.06f);
		playerAnimator->CreateAnimation(L"RollUp", PlayerMotionTex,
			Vector2(0.0f, 1920.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 10, 0.06f);
	}

	void PlayScene::LoadAnimationGrassIdle(Animator* playerAnimator) {
		Graphics::Texture* PlayerMotionTex = Resources::Find<Graphics::Texture>(L"PlayerMotion");

		playerAnimator->CreateAnimation(L"GrassIdleDown", PlayerMotionTex,
			Vector2(0.0f, 2048.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 10, 0.06f);
		playerAnimator->CreateAnimation(L"GrassIdleLeft", PlayerMotionTex,
			Vector2(0.0f, 2176.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 10, 0.06f);
		playerAnimator->CreateAnimation(L"GrassIdleRight", PlayerMotionTex,
			Vector2(0.0f, 2304.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 10, 0.06f);
		playerAnimator->CreateAnimation(L"GrassIdleUp", PlayerMotionTex,
			Vector2(0.0f, 2432.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 10, 0.06f);
	}

	void PlayScene::LoadAnimationGrassWalk(Animator* playerAnimator) {
		Graphics::Texture* PlayerMotionTex = Resources::Find<Graphics::Texture>(L"PlayerMotion");

		playerAnimator->CreateAnimation(L"GrassWalkDown", PlayerMotionTex,
			Vector2(0.0f, 2560.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.06f);
		playerAnimator->CreateAnimation(L"GrassWalkLeft", PlayerMotionTex,
			Vector2(0.0f, 2688.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.06f);
		playerAnimator->CreateAnimation(L"GrassWalkRight", PlayerMotionTex,
			Vector2(0.0f, 2816.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.06f);
		playerAnimator->CreateAnimation(L"GrassWalkUp", PlayerMotionTex,
			Vector2(0.0f, 2944.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.06f);
	}

	void PlayScene::LoadAnimationDeath(Animator* playerAnimator) {
		Graphics::Texture* PlayerMotionTex = Resources::Find<Graphics::Texture>(L"PlayerMotion");

		playerAnimator->CreateAnimation(L"Death", PlayerMotionTex,
			Vector2(0.0f, 3072.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 11, 0.08f);
	}

	void PlayScene::LoadAnimationPendant(Animator* playerAnimator) {
		Graphics::Texture* PlayerMotionTex = Resources::Find<Graphics::Texture>(L"PlayerMotion");

		playerAnimator->CreateAnimation(L"Pendant", PlayerMotionTex,
			Vector2(0.0f, 3200.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 33, 0.08f);

	}

	void PlayScene::LoadAnimationShortSword(Animator* playerAnimator) {
		Graphics::Texture* PlayerAttackTex = Resources::Find<Graphics::Texture>(L"PlayerAttack_SSG");

		playerAnimator->CreateAnimation(L"sSwordAttackDown", PlayerAttackTex,
			Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 18, 0.05f);
		playerAnimator->CreateAnimation(L"sSwordAttackLeft", PlayerAttackTex,
			Vector2(0.0f, 128.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 18, 0.05f);
		playerAnimator->CreateAnimation(L"sSwordAttackRight", PlayerAttackTex,
			Vector2(0.0f, 256.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 18, 0.05f);
		playerAnimator->CreateAnimation(L"sSwordAttackUp", PlayerAttackTex,
			Vector2(0.0f, 384.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 18, 0.05f);
	}

	void PlayScene::LoadAnimationShield(Animator* playerAnimator) {
		Graphics::Texture* PlayerAttackTex = Resources::Find<Graphics::Texture>(L"PlayerAttack_SSG");

		playerAnimator->CreateAnimation(L"ShieldDown", PlayerAttackTex,
			Vector2(0.0f, 512.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 5, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldLeft", PlayerAttackTex,
			Vector2(0.0f, 640.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 5, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldRight", PlayerAttackTex,
			Vector2(0.0f, 768.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 5, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldUp", PlayerAttackTex,
			Vector2(0.0f, 896.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 5, 0.08f);

		playerAnimator->CreateAnimation(L"ShieldOffDown", PlayerAttackTex,
			Vector2(640.0f, 512.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 1, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldOffLeft", PlayerAttackTex,
			Vector2(640.0f, 640.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 1, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldOffRight", PlayerAttackTex,
			Vector2(640.0f, 768.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 1, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldOffUp", PlayerAttackTex,
			Vector2(640.0f, 896.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 1, 0.08f);

		playerAnimator->CreateAnimation(L"ShieldWalkDown", PlayerAttackTex,
			Vector2(896.0f, 512.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldWalkLeft", PlayerAttackTex,
			Vector2(896.0f, 640.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldWalkRight", PlayerAttackTex,
			Vector2(896.0f, 768.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldWalkUp", PlayerAttackTex,
			Vector2(896.0f, 896.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 8, 0.08f);
	}

	void PlayScene::LoadAnimationGloves(Animator* playerAnimator) {
		Graphics::Texture* PlayerAttackTex = Resources::Find<Graphics::Texture>(L"PlayerAttack_SSG");

		playerAnimator->CreateAnimation(L"GloveAttackDown", PlayerAttackTex,
			Vector2(0.0f, 1024.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 20, 0.04f);
		playerAnimator->CreateAnimation(L"GloveAttackLeft", PlayerAttackTex,
			Vector2(0.0f, 1152.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 20, 0.04f);
		playerAnimator->CreateAnimation(L"GloveAttackRight", PlayerAttackTex,
			Vector2(0.0f, 1280.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 20, 0.04f);
		playerAnimator->CreateAnimation(L"GloveAttackUp", PlayerAttackTex,
			Vector2(0.0f, 1408.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 20, 0.04f);

		playerAnimator->CreateAnimation(L"GloveAttack2Down", PlayerAttackTex,
			Vector2(0.0f, 1536.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 11, 0.05f);
		playerAnimator->CreateAnimation(L"GloveAttack2Left", PlayerAttackTex,
			Vector2(0.0f, 1664.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 11, 0.05f);
		playerAnimator->CreateAnimation(L"GloveAttack2Right", PlayerAttackTex,
			Vector2(0.0f, 1792.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 11, 0.05f);
		playerAnimator->CreateAnimation(L"GloveAttack2Up", PlayerAttackTex,
			Vector2(0.0f, 1920.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 11, 0.05f);

		playerAnimator->CreateAnimation(L"GloveAttack2ShotDown", PlayerAttackTex,
			Vector2(1408.0f, 1536.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 5, 0.03f);
		playerAnimator->CreateAnimation(L"GloveAttack2ShotLeft", PlayerAttackTex,
			Vector2(1408.0f, 1664.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 5, 0.03f);
		playerAnimator->CreateAnimation(L"GloveAttack2ShotRight", PlayerAttackTex,
			Vector2(1408.0f, 1792.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 5, 0.03f);
		playerAnimator->CreateAnimation(L"GloveAttack2ShotUp", PlayerAttackTex,
			Vector2(1408.0f, 1920.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 5, 0.03f);
	}
}
