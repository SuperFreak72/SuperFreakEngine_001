#include "SF_PlayScene.h"
#include "SF_GameObject.h"
#include "SF_Player.h"
#include "SF_Monster.h"
#include "SF_AttackDecision.h"
#include "SF_Input.h"
#include "SF_Transform.h"
#include "SF_SpriteRenderer.h"
#include "SF_SceneManager.h"
#include "SF_Object.h"
#include "SF_Resources.h"
#include "SF_PlayerScript.h"
#include "SF_WallScript.h"
#include "SF_MonScript.h"
#include "SF_Camera.h"
#include "SF_Renderer.h"
#include "SF_Animator.h"
#include "SF_BoxCollider2D.h"
#include "SF_CollisionManager.h"
#include "SF_BackGround.h"
#include "SF_WeaponCollision.h"

namespace SF {
	PlayScene::PlayScene()
	: bgSize(4.0f){ }
	PlayScene::~PlayScene() { }

	void PlayScene::Initialize() {
		//배경설정
		bg = Object::Instantiate<BackGround>
			(enums::eLayerType::BackGround);
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		Graphics::Texture* bg = Resources::Find<Graphics::Texture>(L"BG");
		sr->SetTexture(bg);
		sr->SetSize(Vector2(bgSize, bgSize));
		
		//예시 몬스터
		monster = Object::Instantiate<Monster>(enums::eLayerType::Monster);
		monster->AddComponent<MonScript>();
		monster->GetComponent<Transform>()->SetPosition(Vector2(100.0f,100.0f));
		BoxCollider2D* monCollider = monster->AddComponent<BoxCollider2D>();
		monCollider->SetOffset(Vector2::Zero);
		monCollider->SetSize(Vector2(128.0f, 128.0f));

		//플레이어
		player = Object::Instantiate<Player>(enums::eLayerType::Player);
		player->AddComponent<PlayerScript>();
		player->GetComponent<Transform>()->SetPosition(Vector2(1000.0f, 1000.0f));
		player->GetComponent<Transform>()->SetScale(Vector2(4.0f, 4.0f));
		BoxCollider2D* collider = player->AddComponent<BoxCollider2D>();
		collider->SetOffset(Vector2::Zero);
		collider->SetSize(Vector2(128.0f, 128.0f));

		BuildWallCollider();

		Scene::Initialize();
	}

	void PlayScene::Update() {
		Vector2 pPos = player->GetComponent<Transform>()->GetPosition();
		if (pPos.x > 1248.0f && pPos.y < 50.0f && pPos.x < 1488.0f)
			SceneManager::LoadScene(L"CrossroadScene");
		
		
		if (player->GetComponent<PlayerScript>()->GetAttack()) {
			AttackDecision* ad = new AttackDecision();
		}
		
		Scene::Update();
	}

	void PlayScene::LateUpdate() {
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC hdc) {
		Scene::Render(hdc);
	}

	void PlayScene::OnEnter() {
		//카메라
		camera = Object::Instantiate<GameObject>(enums::eLayerType::Particle, Vector2(0.0f, 0.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		Renderer::mainCamera = cameraComp;
		cameraComp->SetTarget(player);

		

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::BackObject, true);
	}

	void PlayScene::OnExit() {
		player->GetComponent<Transform>()->SetPosition(Vector2(1248.0f, 60.0f));
	}

	void PlayScene::BuildWallCollider() {
		BackGround* house1 = Object::Instantiate<BackGround>(enums::eLayerType::BackObject);
		house1->AddComponent<WallScript>();
		Transform* trhouse1 = house1->AddComponent<Transform>();
		trhouse1->SetPosition(Vector2(386.0 * bgSize, 97.0f * bgSize));
		BoxCollider2D* wallCol1 = house1->AddComponent<BoxCollider2D>();
		wallCol1->SetSize(Vector2(139.0f * bgSize, 170.0f * bgSize));
		wallCol1->SetOffset(Vector2::Zero);
		house1->GetComponent<BoxCollider2D>()->SetName(L"house1");

		BackGround* house2 = Object::Instantiate<BackGround>(enums::eLayerType::BackObject);
		house2->AddComponent<WallScript>();
		Transform* trhouse2 = house2->AddComponent<Transform>();
		trhouse2->SetPosition(Vector2(613.0f * bgSize, 213.0f * bgSize));
		BoxCollider2D* wallCol2 = house2->AddComponent<BoxCollider2D>();
		wallCol2->SetSize(Vector2(140.0f * bgSize, 170.0f * bgSize));
		wallCol2->SetOffset(Vector2(-140.0f * bgSize / 2, -170.0f * bgSize / 2));

		BackGround* house3 = Object::Instantiate<BackGround>(enums::eLayerType::BackObject);
		house3->AddComponent<WallScript>();
		Transform* trhouse3 = house3->AddComponent<Transform>();
		trhouse3->SetPosition(Vector2(696.0f * bgSize, 83.0f * bgSize));
		BoxCollider2D* wallCol3 = house3->AddComponent<BoxCollider2D>();
		wallCol3->SetSize(Vector2(224.0f * bgSize, 174.0f * bgSize));
		wallCol3->SetOffset(Vector2::Zero);


	}

	/*void PlayScene::CheckPlayerState() {
		PlayerScript::eState mbState = player->GetComponent<PlayerScript>()->GetState();
		BoxCollider2D* collider = player->GetComponent<BoxCollider2D>();


		switch (mbState)
		{
		case SF::PlayerScript::eState::Idle:
			collider->SetOffset(Vector2::Zero);
			collider->SetSize(Vector2(128.0f, 128.0f));
			break;
		case SF::PlayerScript::eState::Walk:
			collider->SetOffset(Vector2::Zero);
			collider->SetSize(Vector2(128.0f, 128.0f));
			break;
		case SF::PlayerScript::eState::Roll:
			collider->SetOffset(Vector2::Zero);
			collider->SetSize(Vector2(128.0f, 128.0f));
			break;
		case SF::PlayerScript::eState::Swim:
			break;
		case SF::PlayerScript::eState::Grass:
			break;
		case SF::PlayerScript::eState::GrassWalk:
			break;
		case SF::PlayerScript::eState::Attack1:
			ChangeCollistionByState();
			break;
		case SF::PlayerScript::eState::Attack2:
			ChangeCollistionByState();
			break;
		case SF::PlayerScript::eState::Attack2Shot:
			break;
		case SF::PlayerScript::eState::Attack2Shot2:
			break;
		case SF::PlayerScript::eState::Death:
			break;
		case SF::PlayerScript::eState::Pendant:
			break;
		case SF::PlayerScript::eState::Glove:
			break;
		default:
			break;
		}
	}

	void PlayScene::ChangeCollistionByState() {
		PlayerScript::eDirection mbDirection = player->GetComponent<PlayerScript>()->GetDirection();
		PlayerScript::eWeapon mbWeapon = player->GetComponent<PlayerScript>()->GetWeapon();
		WeaponCollision wCollision;
		BoxCollider2D* collider = player->GetComponent<BoxCollider2D>();

		switch (mbDirection) {
		case SF::PlayerScript::eDirection::Left:
			collider->SetOffset(wCollision.GetOffset(L"ShortSwordLeft"));
			break;
		case SF::PlayerScript::eDirection::Right:
			collider->SetOffset(wCollision.GetOffset(L"ShortSwordRight"));
			break;
		case SF::PlayerScript::eDirection::Down:
			collider->SetOffset(wCollision.GetOffset(L"ShortSwordDown"));
			break;
		case SF::PlayerScript::eDirection::Up:
			collider->SetOffset(wCollision.GetOffset(L"ShortSwordUp"));
			break;
		case SF::PlayerScript::eDirection::End:
			break;
		default:
			assert(false);
		}

		switch (mbWeapon) {
		case SF::PlayerScript::eWeapon::ShortSword:
			collider->SetSize(wCollision.GetWeapon(L"ShortSword"));
			break;
		case SF::PlayerScript::eWeapon::Gloves:
			collider->SetSize(wCollision.GetWeapon(L"ShortSword"));
			break;
		case SF::PlayerScript::eWeapon::BigSword:
			collider->SetSize(wCollision.GetWeapon(L"ShortSword"));
			break;
		case SF::PlayerScript::eWeapon::Spear:
			collider->SetSize(wCollision.GetWeapon(L"ShortSword"));
			break;
		case SF::PlayerScript::eWeapon::Bow:
			collider->SetSize(wCollision.GetWeapon(L"ShortSword"));
			break;
		default:
			assert(false);
		}
	}*/
}
