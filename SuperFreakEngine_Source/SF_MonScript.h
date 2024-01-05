#pragma once
#include "SF_Script.h"
#include "SF_Transform.h"

namespace SF {
	class MonScript : public Script {
	public :
		enum class eState {
			Idle,
			Move,
			Attack,
			Damaged,
		};
		enum class eDirection {
			Left,
			Right,
			Down,
			Up,
			End,
		};

		MonScript();
		~MonScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		eDirection GetDirection() { return mDirection; }
		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

	private:
		void Idle();
		void Move();
		void Attack();
		void Damaged();
	private:
		eState mState;
		eDirection mDirection;
		class Animator* mAnimator;
		float mTime = 0.0f;
	};

}
