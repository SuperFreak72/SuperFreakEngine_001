#include "SF_PlayerScript.h"
#include "SF_Input.h"
#include "SF_Transform.h"
#include "SF_Time.h"
#include "SF_GameObject.h"
#include "SF_Animator.h"
#include "SF_Object.h"
#include "SF_Resources.h"

namespace SF {
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Stand)
		, mDirection(PlayerScript::eDirection::Down)
		, mAnimator(nullptr)
		, mb_Complete(true)
	{}
	PlayerScript::~PlayerScript() {}
	
	void PlayerScript::Initialize() {}

	void PlayerScript::Update() {
		if (mAnimator == nullptr) {
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState) {
		case SF::PlayerScript::eState::Stand:
			Stand();
			break;
		case SF::PlayerScript::eState::Walk:
			Move();
			break;
		case SF::PlayerScript::eState::Roll:
			Roll();
			break;
		case SF::PlayerScript::eState::Glove:
			Glove();
			break;
		default:
			break;
		}
	}

	void PlayerScript::LateUpdate() {}

	void PlayerScript::Render(HDC hdc) {}

	void PlayerScript::Stand() {
		if (Input::GetKey(eKeyCode::D)) //Right Move
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"RightWalk");
		}
		if (Input::GetKey(eKeyCode::A)) //Left Move
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"LeftWalk");
		}
		if (Input::GetKey(eKeyCode::W)) //Up Move
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"UpWalk");
		}
		if (Input::GetKey(eKeyCode::S)) //Down Move
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"DownWalk");
		}
		if (Input::GetKey(eKeyCode::Space)) //Roll
		{
			TurnRoll();
		}
		if (Input::GetKey(eKeyCode::J)) //Punch!!
		{
			TurnGlove();
		}
	}

	void PlayerScript::Move() {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::D))
		{
			mDirection = PlayerScript::eDirection::Right;
			pos.x += 200.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			mDirection = PlayerScript::eDirection::Left;
			pos.x -= 200.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::W))
		{
			mDirection = PlayerScript::eDirection::Up;
			pos.y -= 200.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mDirection = PlayerScript::eDirection::Down;
			pos.y += 200.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Space)) //Roll
		{
			TurnRoll();
		}
		if (Input::GetKey(eKeyCode::J)) //Punch!!
		{
			TurnGlove();
		}

		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::D))
		{
			TurnIdle();

		}
		if (Input::GetKeyUp(eKeyCode::A))
		{
			TurnIdle();
	
		}
		if (Input::GetKeyUp(eKeyCode::W))
		{
			TurnIdle();

		}
		if (Input::GetKeyUp(eKeyCode::S))
		{
			TurnIdle();
		}
	}

	void PlayerScript::Roll() {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (mAnimator->IsComplete()) {
			TurnIdle();
		}
		else {
			switch (mDirection) {
			case PlayerScript::eDirection::Left:
				pos.x -= 400.0f * Time::DeltaTime();
				break;
			case PlayerScript::eDirection::Right:
				pos.x += 400.0f * Time::DeltaTime();
				break;
			case PlayerScript::eDirection::Up:
				pos.y -= 400.0f * Time::DeltaTime();
				break;
			case PlayerScript::eDirection::Down:
				pos.y += 400.0f * Time::DeltaTime();
				break;
			}
		}

		tr->SetPosition(pos);
	}

	void PlayerScript::Glove() {
		if (mAnimator->IsComplete()) {
			TurnIdle();
		}
	}

	void PlayerScript::TurnIdle() {
		switch (mDirection) {
		case PlayerScript::eDirection::Left:
			mState = PlayerScript::eState::Stand;
			mDirection = PlayerScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftIdle", true);

			break;
		case PlayerScript::eDirection::Right:
			mState = PlayerScript::eState::Stand;
			mDirection = PlayerScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightIdle", true);

			break;
		case PlayerScript::eDirection::Up:
			mState = PlayerScript::eState::Stand;
			mDirection = PlayerScript::eDirection::Up;
			mAnimator->PlayAnimation(L"UpIdle", true);

			break;
		case PlayerScript::eDirection::Down:
			mState = PlayerScript::eState::Stand;
			mDirection = PlayerScript::eDirection::Down;
			mAnimator->PlayAnimation(L"DownIdle", true);

			break;
		}
	}

	void PlayerScript::TurnRoll() {
		mState = PlayerScript::eState::Roll;
		switch (mDirection) {
		case SF::PlayerScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftRoll", false);
			break;
		case SF::PlayerScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightRoll", false);
			break;
		case SF::PlayerScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpRoll", false);
			break;
		case SF::PlayerScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownRoll", false);
			break;
		}
	}

	void PlayerScript::TurnGlove() {
		mState = PlayerScript::eState::Glove;
		switch (mDirection) {
		case SF::PlayerScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftPunch", false);
			break;
		case SF::PlayerScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightPunch", false);
			break;
		case SF::PlayerScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpPunch", false);
			break;
		case SF::PlayerScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownPunch", false);
			break;
		}
	}
}
