#include "SF_PlayScene.h"
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


namespace SF {
	PlayScene::PlayScene() { }
	PlayScene::~PlayScene() { }

	void PlayScene::Initialize() {
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Player, true);

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
		BoxCollider2D* collider = player->AddComponent<BoxCollider2D>();
		collider->SetOffset(Vector2::Zero);

		
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
		LoadAnimationBigSword(playerAnimator);
		LoadAnimationSpear(playerAnimator);
		
		playerAnimator->PlayAnimation(L"IdleDown", true);
		player->GetComponent<Transform>()->SetPosition(Vector2(128.0f, 128.0f));
		player->GetComponent<Transform>()->SetScale(Vector2(3.0f, 3.0f));
	}

	void PlayScene::LoadAnimationIdle(Animator* playerAnimator) {
		Graphics::Texture* PlayerMotionTex = Resources::Find<Graphics::Texture>(L"PlayerMotion");
		Vector2 pScale = player->GetComponent<Transform>()->GetScale();
		float pScaleX = pScale.x;
		float pScaneY = pScale.y;

		playerAnimator->CreateAnimation(L"IdleDown", PlayerMotionTex,
			Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 10, 0.07f);
		playerAnimator->CreateAnimation(L"IdleLeft", PlayerMotionTex,
			Vector2(0.0f, 128.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 10, 0.07f);
		playerAnimator->CreateAnimation(L"IdleRight", PlayerMotionTex,
			Vector2(0.0f, 256.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 10, 0.07f);
		playerAnimator->CreateAnimation(L"IdleUp", PlayerMotionTex,
			Vector2(0.0f, 384.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 10, 0.07f);
	}

	void PlayScene::LoadAnimationWalk(Animator* playerAnimator) {
		Graphics::Texture* PlayerMotionTex = Resources::Find<Graphics::Texture>(L"PlayerMotion");

		playerAnimator->CreateAnimation(L"WalkDown", PlayerMotionTex,
			Vector2(0.0f, 512.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 8, 0.06f);
		playerAnimator->CreateAnimation(L"WalkLeft", PlayerMotionTex,
			Vector2(0.0f, 640.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 8, 0.06f);
		playerAnimator->CreateAnimation(L"WalkRight", PlayerMotionTex,
			Vector2(0.0f, 768.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 8, 0.06f);
		playerAnimator->CreateAnimation(L"WalkUp", PlayerMotionTex,
			Vector2(0.0f, 896.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 8, 0.06f);
	}

	void PlayScene::LoadAnimationRoll(Animator* playerAnimator) {
		Graphics::Texture* PlayerMotionTex = Resources::Find<Graphics::Texture>(L"PlayerMotion");

		playerAnimator->CreateAnimation(L"RollDown", PlayerMotionTex,
			Vector2(0.0f, 1024.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 8, 0.06f);
		playerAnimator->CreateAnimation(L"RollLeft", PlayerMotionTex,
			Vector2(0.0f, 1152.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 8, 0.06f);
		playerAnimator->CreateAnimation(L"RollRight", PlayerMotionTex,
			Vector2(0.0f, 1280.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 8, 0.06f);
		playerAnimator->CreateAnimation(L"RollUp", PlayerMotionTex,
			Vector2(0.0f, 1408.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 8, 0.06f);
	}

	void PlayScene::LoadAniamtionSwim(Animator* playerAnimator) {
		Graphics::Texture* PlayerMotionTex = Resources::Find<Graphics::Texture>(L"PlayerMotion");

		playerAnimator->CreateAnimation(L"SwimDown", PlayerMotionTex,
			Vector2(0.0f, 1536.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 10, 0.06f);
		playerAnimator->CreateAnimation(L"RollLeft", PlayerMotionTex,
			Vector2(0.0f, 1664.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 10, 0.06f);
		playerAnimator->CreateAnimation(L"RollRight", PlayerMotionTex,
			Vector2(0.0f, 1792.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 10, 0.06f);
		playerAnimator->CreateAnimation(L"RollUp", PlayerMotionTex,
			Vector2(0.0f, 1920.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 10, 0.06f);
	}

	void PlayScene::LoadAnimationGrassIdle(Animator* playerAnimator) {
		Graphics::Texture* PlayerMotionTex = Resources::Find<Graphics::Texture>(L"PlayerMotion");

		playerAnimator->CreateAnimation(L"GrassIdleDown", PlayerMotionTex,
			Vector2(0.0f, 2048.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 10, 0.06f);
		playerAnimator->CreateAnimation(L"GrassIdleLeft", PlayerMotionTex,
			Vector2(0.0f, 2176.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 10, 0.06f);
		playerAnimator->CreateAnimation(L"GrassIdleRight", PlayerMotionTex,
			Vector2(0.0f, 2304.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 10, 0.06f);
		playerAnimator->CreateAnimation(L"GrassIdleUp", PlayerMotionTex,
			Vector2(0.0f, 2432.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 10, 0.06f);
	}

	void PlayScene::LoadAnimationGrassWalk(Animator* playerAnimator) {
		Graphics::Texture* PlayerMotionTex = Resources::Find<Graphics::Texture>(L"PlayerMotion");

		playerAnimator->CreateAnimation(L"GrassWalkDown", PlayerMotionTex,
			Vector2(0.0f, 2560.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 8, 0.06f);
		playerAnimator->CreateAnimation(L"GrassWalkLeft", PlayerMotionTex,
			Vector2(0.0f, 2688.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 8, 0.06f);
		playerAnimator->CreateAnimation(L"GrassWalkRight", PlayerMotionTex,
			Vector2(0.0f, 2816.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 8, 0.06f);
		playerAnimator->CreateAnimation(L"GrassWalkUp", PlayerMotionTex,
			Vector2(0.0f, 2944.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 8, 0.06f);
	}

	void PlayScene::LoadAnimationDeath(Animator* playerAnimator) {
		Graphics::Texture* PlayerMotionTex = Resources::Find<Graphics::Texture>(L"PlayerMotion");

		playerAnimator->CreateAnimation(L"Death", PlayerMotionTex,
			Vector2(0.0f, 3072.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 11, 0.08f);
	}

	void PlayScene::LoadAnimationPendant(Animator* playerAnimator) {
		Graphics::Texture* PlayerMotionTex = Resources::Find<Graphics::Texture>(L"PlayerMotion");

		playerAnimator->CreateAnimation(L"Pendant", PlayerMotionTex,
			Vector2(0.0f, 3200.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 33, 0.08f);

	}

	void PlayScene::LoadAnimationShortSword(Animator* playerAnimator) {
		Graphics::Texture* PlayerAttackTex = Resources::Find<Graphics::Texture>(L"PlayerAttack_SS");

		playerAnimator->CreateAnimation(L"sSwordAttackDown", PlayerAttackTex,
			Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 18, 0.05f);
		playerAnimator->CreateAnimation(L"sSwordAttackLeft", PlayerAttackTex,
			Vector2(0.0f, 128.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 18, 0.05f);
		playerAnimator->CreateAnimation(L"sSwordAttackRight", PlayerAttackTex,
			Vector2(0.0f, 256.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 18, 0.05f);
		playerAnimator->CreateAnimation(L"sSwordAttackUp", PlayerAttackTex,
			Vector2(0.0f, 384.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 18, 0.05f);
	}

	void PlayScene::LoadAnimationShield(Animator* playerAnimator) {
		Graphics::Texture* PlayerAttackTex = Resources::Find<Graphics::Texture>(L"PlayerAttack_SS");

		playerAnimator->CreateAnimation(L"ShieldDown", PlayerAttackTex,
			Vector2(0.0f, 512.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 5, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldLeft", PlayerAttackTex,
			Vector2(0.0f, 640.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 5, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldRight", PlayerAttackTex,
			Vector2(0.0f, 768.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 5, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldUp", PlayerAttackTex,
			Vector2(0.0f, 896.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 5, 0.08f);

		playerAnimator->CreateAnimation(L"ShieldOffDown", PlayerAttackTex,
			Vector2(640.0f, 512.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 1, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldOffLeft", PlayerAttackTex,
			Vector2(640.0f, 640.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 1, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldOffRight", PlayerAttackTex,
			Vector2(640.0f, 768.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 1, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldOffUp", PlayerAttackTex,
			Vector2(640.0f, 896.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 1, 0.08f);

		playerAnimator->CreateAnimation(L"ShieldWalkDown", PlayerAttackTex,
			Vector2(896.0f, 512.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 8, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldWalkLeft", PlayerAttackTex,
			Vector2(896.0f, 640.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 8, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldWalkRight", PlayerAttackTex,
			Vector2(896.0f, 768.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 8, 0.08f);
		playerAnimator->CreateAnimation(L"ShieldWalkUp", PlayerAttackTex,
			Vector2(896.0f, 896.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 8, 0.08f);
	}

	void PlayScene::LoadAnimationGloves(Animator* playerAnimator) {
		Graphics::Texture* PlayerAttackTex = Resources::Find<Graphics::Texture>(L"PlayerAttack_G");

		playerAnimator->CreateAnimation(L"GloveAttackDown", PlayerAttackTex,
			Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 20, 0.04f);
		playerAnimator->CreateAnimation(L"GloveAttackLeft", PlayerAttackTex,
			Vector2(0.0f, 128.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 20, 0.04f);
		playerAnimator->CreateAnimation(L"GloveAttackRight", PlayerAttackTex,
			Vector2(0.0f, 256.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 20, 0.04f);
		playerAnimator->CreateAnimation(L"GloveAttackUp", PlayerAttackTex,
			Vector2(0.0f, 384.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 20, 0.04f);

		playerAnimator->CreateAnimation(L"GloveAttack2Down", PlayerAttackTex,
			Vector2(0.0f, 512.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 11, 0.05f);
		playerAnimator->CreateAnimation(L"GloveAttack2Left", PlayerAttackTex,
			Vector2(0.0f, 640.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 11, 0.05f);
		playerAnimator->CreateAnimation(L"GloveAttack2Right", PlayerAttackTex,
			Vector2(0.0f, 768.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 11, 0.05f);
		playerAnimator->CreateAnimation(L"GloveAttack2Up", PlayerAttackTex,
			Vector2(0.0f, 896.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 11, 0.05f);

		playerAnimator->CreateAnimation(L"GloveAttack2ShotDown", PlayerAttackTex,
			Vector2(1408.0f, 512.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 5, 0.04f);
		playerAnimator->CreateAnimation(L"GloveAttack2ShotLeft", PlayerAttackTex,
			Vector2(1408.0f, 640.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 5, 0.04f);
		playerAnimator->CreateAnimation(L"GloveAttack2ShotRight", PlayerAttackTex,
			Vector2(1408.0f, 768.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 5, 0.04f);
		playerAnimator->CreateAnimation(L"GloveAttack2ShotUp", PlayerAttackTex,
			Vector2(1408.0f, 896.0f), Vector2(128.0f, 128.0f), Vector2(-64.0f, -64.0f), 5, 0.04f);
	}
	void PlayScene::LoadAnimationBigSword(Animator* playerAnimator) {
		Graphics::Texture* PlayerAttackTex = Resources::Find<Graphics::Texture>(L"PlayerAttack_BS");

		playerAnimator->CreateAnimation(L"BigSwordAttackDown", PlayerAttackTex,
			Vector2(0.0f, 0.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 40, 0.06f);
		playerAnimator->CreateAnimation(L"BigSwordAttackLeft", PlayerAttackTex,
			Vector2(0.0f, 256.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 40, 0.06f);
		playerAnimator->CreateAnimation(L"BigSwordAttackRight", PlayerAttackTex,
			Vector2(0.0f, 512.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 40, 0.06f);
		playerAnimator->CreateAnimation(L"BigSwordAttackUp", PlayerAttackTex,
			Vector2(0.0f, 768.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 40, 0.06f);

		playerAnimator->CreateAnimation(L"BigSwordSpin", PlayerAttackTex,
			Vector2(0.0f, 1024.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 31, 0.07f);

	}
	void PlayScene::LoadAnimationSpear(Animator* playerAnimator) {
		Graphics::Texture* PlayerAttackTex = Resources::Find<Graphics::Texture>(L"PlayerAttack_S");

		playerAnimator->CreateAnimation(L"SpearAttackDown", PlayerAttackTex,
			Vector2(0.0f, 0.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 23, 0.04f);
		playerAnimator->CreateAnimation(L"SpearAttackLeft", PlayerAttackTex,
			Vector2(0.0f, 256.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 23, 0.04f);
		playerAnimator->CreateAnimation(L"SpearAttackRight", PlayerAttackTex,
			Vector2(0.0f, 512.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 23, 0.04f);
		playerAnimator->CreateAnimation(L"SpearAttackUp", PlayerAttackTex,
			Vector2(0.0f, 768.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 23, 0.04f);

		playerAnimator->CreateAnimation(L"SpearAttack2Down", PlayerAttackTex,
			Vector2(0.0f, 1024.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 19, 0.06f);
		playerAnimator->CreateAnimation(L"SpearAttack2Left", PlayerAttackTex,
			Vector2(0.0f, 1280.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 19, 0.06f);
		playerAnimator->CreateAnimation(L"SpearAttack2Right", PlayerAttackTex,
			Vector2(0.0f, 1536.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 19, 0.06f);
		playerAnimator->CreateAnimation(L"SpearAttack2Up", PlayerAttackTex,
			Vector2(0.0f, 1792.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 19, 0.06f);

		playerAnimator->CreateAnimation(L"SpearAttack2ShotDown", PlayerAttackTex,
			Vector2(4864.0f, 1024.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 15, 0.04f);
		playerAnimator->CreateAnimation(L"SpearAttack2ShotLeft", PlayerAttackTex,
			Vector2(4864.0f, 1280.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 15, 0.04f);
		playerAnimator->CreateAnimation(L"SpearAttack2ShotRight", PlayerAttackTex,
			Vector2(4864.0f, 1536.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 15, 0.04f);
		playerAnimator->CreateAnimation(L"SpearAttack2ShotUp", PlayerAttackTex,
			Vector2(4864.0f, 1792.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 15, 0.04f);

		playerAnimator->CreateAnimation(L"SpearAttack2Shot2Down", PlayerAttackTex,
			Vector2(8704.0f, 1024.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 10, 0.06f);
		playerAnimator->CreateAnimation(L"SpearAttack2Shot2Left", PlayerAttackTex,
			Vector2(8704.0f, 1280.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 10, 0.06f);
		playerAnimator->CreateAnimation(L"SpearAttack2Shot2Right", PlayerAttackTex,
			Vector2(8704.0f, 1536.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 10, 0.06f);
		playerAnimator->CreateAnimation(L"SpearAttack2Shot2Up", PlayerAttackTex,
			Vector2(8704.0f, 1792.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 10, 0.06f);



		playerAnimator->CreateAnimation(L"BigSwordSpin", PlayerAttackTex,
			Vector2(0.0f, 1024.0f), Vector2(256.0f, 256.0f), Vector2(-192.0f, -192.0f), 31, 0.07f);

	}
}
