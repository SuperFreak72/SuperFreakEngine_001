#include "SF_TitleScene.h"
#include "SF_GameObject.h"
#include "SF_Transform.h"
#include "SF_Component.h"
#include "SF_BackGround.h"
#include "SF_Player.h"
#include "SF_Input.h"
#include "SF_Time.h"
#include "SF_Transform.h"
#include "SF_SpriteRenderer.h"
#include "SF_SceneManager.h"
#include "SF_Object.h"
#include "SF_Resources.h"
#include "SF_Renderer.h"
#include "SF_Animator.h"

namespace SF {
	TitleScene::TitleScene()
	: backBubble(nullptr)
	, frontBubble(nullptr)
	, leftWall(nullptr)
	, rightWall(nullptr)
	, logo(nullptr)
	, light(nullptr)
	, mTime(0.0f)
	, mDoorSpeed(1200.0f)
	{}

	TitleScene::~TitleScene() {}
	
	void TitleScene::Initialize() {
		backBubble = Object::Instantiate<BackGround> (enums::eLayerType::BackGround);
		frontBubble = Object::Instantiate<BackGround>(enums::eLayerType::BackObject);
		leftWall = Object::Instantiate<BackGround>(enums::eLayerType::Player);
		rightWall = Object::Instantiate<BackGround>(enums::eLayerType::Player);
		light = Object::Instantiate<BackGround>(enums::eLayerType::Monster);
		logo = Object::Instantiate<BackGround>(enums::eLayerType::Particle);

		
		SpriteRenderer* srLeft = leftWall->AddComponent<SpriteRenderer>();
		SpriteRenderer* srRight = rightWall->AddComponent<SpriteRenderer>();
		SpriteRenderer* srLogo = logo->AddComponent<SpriteRenderer>();
		SpriteRenderer* srLight = light->AddComponent<SpriteRenderer>();

		Graphics::Texture* LWall = Resources::Find<Graphics::Texture>(L"LeftWall");
		Graphics::Texture* RWall = Resources::Find<Graphics::Texture>(L"RightWall");
		Graphics::Texture* LogoTex = Resources::Find<Graphics::Texture>(L"Logo");
		Graphics::Texture* LightTex = Resources::Find<Graphics::Texture>(L"Light");

		srLeft->SetTexture(LWall);
		srRight->SetTexture(RWall);
		srLogo->SetTexture(LogoTex);
		srLight->SetTexture(LightTex);
		
		Animator* backBubbleAnimator = backBubble->AddComponent<Animator>();
		Animator* frontBubbleAnimator = frontBubble->AddComponent<Animator>();
		LoadAnimationBackBubble(backBubbleAnimator);
		LoadAnimationFrontBubble(frontBubbleAnimator);

		backBubble->GetComponent<Transform>()->SetPosition(Vector2::Zero);
		frontBubble->GetComponent<Transform>()->SetPosition(Vector2::Zero);
		backBubble->GetComponent<Transform>()->SetScale(Vector2(3.5f, 3.5f));
		frontBubble->GetComponent<Transform>()->SetScale(Vector2(3.5f, 3.5f));

		leftWall->GetComponent<Transform>()->SetPosition(Vector2(0.0f, -30.0f));
		rightWall->GetComponent<Transform>()->SetPosition(Vector2(964.0f, -30.0f));
		logo->GetComponent<Transform>()->SetPosition(Vector2(756.0f, 80.0f));
		light->GetComponent<Transform>()->SetPosition(Vector2(-10.0f, 0.0f));
		srLeft->SetSize(Vector2(3.0f, 3.0f));
		srRight->SetSize(Vector2(3.0f, 3.0f));
		srLogo->SetSize(Vector2(0.12f, 0.12f));
		srLight->SetSize(Vector2(3.0f, 3.0f));

		Scene::Initialize();
	}
	void TitleScene::Update() {
		if (!mb_openWall) {
			if (Input::GetKeyDown(eKeyCode::J)|| Input::GetKeyDown(eKeyCode::K)|| Input::GetKeyDown(eKeyCode::W)||
				Input::GetKeyDown(eKeyCode::A)|| Input::GetKeyDown(eKeyCode::S)|| Input::GetKeyDown(eKeyCode::D)||
				Input::GetKeyDown(eKeyCode::Space)) 
			{
				mb_openWall = true;
			}
		}
		else {
			light->SetActive(false);
			mTime += Time::DeltaTime();
			Transform* trLeft = leftWall->GetComponent<Transform>();
			Transform* trRight = rightWall->GetComponent<Transform>();
			Vector2 LwallPos = trLeft->GetPosition();
			Vector2 RwallPos = trRight->GetPosition();

			if (mTime < 0.5f) {
				LwallPos.x -= mDoorSpeed * Time::DeltaTime();
				RwallPos.x += mDoorSpeed * Time::DeltaTime();
				trLeft->SetPosition(LwallPos);
				trRight->SetPosition(RwallPos);
			}
		}

		Scene::Update();
	}
	void TitleScene::LateUpdate() {
		Scene::LateUpdate();
	}
	void TitleScene::Render(HDC hdc) {
		Scene::Render(hdc);
	}
	void TitleScene::OnEnter() {}
	void TitleScene::OnExit() {}
	void TitleScene::LoadAnimationBackBubble(Animator* value) {
		Graphics::Texture* BubbleTex = Resources::Find<Graphics::Texture>(L"TitleBubble");

		value->CreateAnimation(L"BackBubble", BubbleTex,
			Vector2(0.0f, 360.0f), Vector2(640.0f, 360.0f), Vector2::Zero, 16, 0.09f);

		value->PlayAnimation(L"BackBubble", true);
	}

	void TitleScene::LoadAnimationFrontBubble(Animator* value) {
		Graphics::Texture* BubbleTex = Resources::Find<Graphics::Texture>(L"TitleBubble");

		value->CreateAnimation(L"FrontBubble", BubbleTex,
			Vector2(0.0f, 0.0f), Vector2(640.0f, 360.0f), Vector2::Zero, 16, 0.09f);

		value->PlayAnimation(L"FrontBubble", true);
	}
	void TitleScene::AnimationOpenWall() {

	}
}