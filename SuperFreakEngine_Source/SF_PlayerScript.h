#pragma once
#include "SF_Script.h"
#include "SF_Transform.h"

namespace SF {
	class PlayerScript : public Script {
	public :
		enum class eState {
			Stand,
			Walk,
			Roll,
			Grass,
			Glove,
			
		};
		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
			End,
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		eDirection GetDirection() { return mDirection; }
	private:
		void Stand();
		void Move();
		void Roll();
		void Glove();
		void TurnIdle();
		void TurnRoll();
		void TurnGlove();

	private:
		eState mState;
		eDirection mDirection;
		class Animator* mAnimator;
		bool mb_Complete;
	};
}

