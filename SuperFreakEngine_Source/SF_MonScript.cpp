#include "SF_MonScript.h"
#include "SF_Input.h"
#include "SF_Transform.h"
#include "SF_Time.h"
#include "SF_GameObject.h"
#include "SF_Animator.h"
#include "SF_Object.h"
#include "SF_Resources.h"

namespace SF {
	MonScript::MonScript()
		: mState(MonScript::eState::Idle)
		, mDirection(MonScript::eDirection::Down)
		, mAnimator(nullptr)
	{}
	MonScript::~MonScript() {}

	void MonScript::Initialize() {}

	void MonScript::Update() {
		switch (mState) {
		case MonScript::eState::Idle:
			Idle();
			break;
		case MonScript::eState::Move:
			Move();
			break;
		case MonScript::eState::Attack:
			Attack();
			break;
		case MonScript::eState::Damaged:
			Damaged();
			break;
		}
	}

	void MonScript::LateUpdate() {}

	void MonScript::Render(HDC hdc) {
		
	}

	void MonScript::OnCollisionEnter(Collider* other) {
		int a = 0;
	}

	void MonScript::OnCollisionStay(Collider* other) {}

	void MonScript::OnCollisionExit(Collider* other) {}

	void MonScript::Idle() {
		srand((UINT)time(NULL));
		int num = rand() % 4;
		mTime += Time::DeltaTime();

		if (mTime > 2.0f) {
			switch (num) {
			case 0:
				mDirection = eDirection::Left;
				mState = eState::Move;
				mTime = 0.0f;
				break;
			case 1:
				mDirection = eDirection::Right;
				mState = eState::Move;
				mTime = 0.0f;
				break;
			case 2:
				mDirection = eDirection::Down;
				mState = eState::Move;
				mTime = 0.0f;
				break;
			case 3:
				mDirection = eDirection::Up;
				mState = eState::Move;
				mTime = 0.0f;
				break;
			default:
				assert(false);
			}
		}
	}

	void MonScript::Move() {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		mTime += Time::DeltaTime();

		if (mTime < 1.0f) {
			switch (mDirection) {
			case MonScript::eDirection::Down:
				pos.y += 200.0f * Time::DeltaTime();
				break;
			case MonScript::eDirection::Left:
				pos.x += 200.0f * Time::DeltaTime();
				break;
			case MonScript::eDirection::Right:
				pos.x -= 200.0f * Time::DeltaTime();
				break;
			case MonScript::eDirection::Up:
				pos.y -= 200.0f * Time::DeltaTime();
				break;
			}

			tr->SetPosition(pos);
		}
		else if (mTime > 3.0f) {
			mTime = 0.0f;
			mState = eState::Idle;
		}
	}

	void MonScript::Attack() {}

	void MonScript::Damaged() {}

}
