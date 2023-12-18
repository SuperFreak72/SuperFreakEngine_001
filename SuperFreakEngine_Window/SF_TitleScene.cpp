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
#include "tchar.h"

namespace SF {
	TitleScene::TitleScene()
	: backBubble(nullptr)
	, frontBubble(nullptr)
	, leftWall(nullptr)
	, rightWall(nullptr)
	, logo(nullptr)
	, mb_openWall(false)
	, mb_chooseButton(false)
	, mTime(0.0f)
	, mMenu(TitleScene::eMenu::NewGame)
	, mDoorSpeed(1400.0f)
	{}

	TitleScene::~TitleScene() {}
	
	void TitleScene::Initialize() {
		backBubble = Object::Instantiate<BackGround> (enums::eLayerType::BackGround);
		frontBubble = Object::Instantiate<BackGround>(enums::eLayerType::BackObject);
		mSelectLeft = Object::Instantiate<BackGround>(enums::eLayerType::BackUI);
		mSelectRight = Object::Instantiate<BackGround>(enums::eLayerType::BackUI);
		leftWall = Object::Instantiate<BackGround>(enums::eLayerType::Player);
		rightWall = Object::Instantiate<BackGround>(enums::eLayerType::Player);
		logo = Object::Instantiate<BackGround>(enums::eLayerType::Particle);


		
		SpriteRenderer* srLeft = leftWall->AddComponent<SpriteRenderer>();
		SpriteRenderer* srRight = rightWall->AddComponent<SpriteRenderer>();
		SpriteRenderer* srLogo = logo->AddComponent<SpriteRenderer>();
		SpriteRenderer* srSelectL = mSelectLeft->AddComponent<SpriteRenderer>();
		SpriteRenderer* srSelectR = mSelectRight->AddComponent<SpriteRenderer>();

		Graphics::Texture* LWall = Resources::Find<Graphics::Texture>(L"LeftWall");
		Graphics::Texture* RWall = Resources::Find<Graphics::Texture>(L"RightWall");
		Graphics::Texture* LogoTex = Resources::Find<Graphics::Texture>(L"Logo");
		Graphics::Texture* SelectL = Resources::Find<Graphics::Texture>(L"UI_SelectL");
		Graphics::Texture* SelectR = Resources::Find<Graphics::Texture>(L"UI_SelectR");

		srLeft->SetTexture(LWall);
		srRight->SetTexture(RWall);
		srLogo->SetTexture(LogoTex);
		srSelectL->SetTexture(SelectL);
		srSelectR->SetTexture(SelectR);
		
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
		mSelectLeft->GetComponent<Transform>()->SetPosition(Vector2(830.0f, 590.0f));
		mSelectRight->GetComponent<Transform>()->SetPosition(Vector2(1035.0f, 590.0f));
		srLeft->SetSize(Vector2(3.0f, 3.0f));
		srRight->SetSize(Vector2(3.0f, 3.0f));
		srLogo->SetSize(Vector2(0.12f, 0.12f));
		srSelectR->SetSize(Vector2(3.0f, 3.0f));
		srSelectL->SetSize(Vector2(3.0f, 3.0f));

		Scene::Initialize();
	}

	void TitleScene::Update() {
		if (!mb_openWall) {
			if (Input::GetKeyDown(eKeyCode::J)|| Input::GetKeyDown(eKeyCode::K)|| Input::GetKeyDown(eKeyCode::W)||
				Input::GetKeyDown(eKeyCode::A)|| Input::GetKeyDown(eKeyCode::S)|| Input::GetKeyDown(eKeyCode::D)||
				Input::GetKeyDown(eKeyCode::Space)) 
			{
				mb_openWall = true;
				mb_chooseButton = true;
			}
		}
		else {
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

		HFONT hFont, oldFont;
		SetBkMode(hdc, TRANSPARENT);
		SetTextColor(hdc, RGB(255, 255, 255));
		hFont = CreateFont(32, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("제주고딕"));
		oldFont = (HFONT)SelectObject(hdc, hFont);

		if (!mb_openWall) {
			wchar_t tClick[50] = L"계속하려면 아무 키를 누르세요";

			TextOut(hdc, 760, 860, tClick, lstrlenW(tClick));

			SelectObject(hdc, oldFont);
			DeleteObject(hFont);
		}
		else {
			wchar_t tContinue[50] = L"계속하기";
			wchar_t tLoad[100] = L"게임 불러오기 / 새로운 게임 / 새 게임 플러스";
			wchar_t tOption[50] = L"옵션";
			wchar_t tExit[50] = L"종료";

			TextOut(hdc, 900, 600, tContinue, lstrlenW(tContinue));
			TextOut(hdc, 657, 680, tLoad, lstrlenW(tLoad));
			TextOut(hdc, 928, 760, tOption, lstrlenW(tOption));
			TextOut(hdc, 928, 840, tExit, lstrlenW(tExit));
			
			SelectObject(hdc, oldFont);
			DeleteObject(hFont);
		}
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
}