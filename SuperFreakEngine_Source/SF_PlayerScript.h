#pragma once
#include "SF_Script.h"
#include "SF_Transform.h"

namespace SF {
	class PlayerScript : public Script {
	public :
		enum class eState {
			Idle,
			Walk,
			Roll,
			Swim,
			Grass,
			GrassWalk,
			Attack1,
			Attack2,
			Attack2Shot,
			Death,
			Pendant,
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
		enum class eWeapon {
			ShortSword,
			Gloves,
			BigSword,
			Spear,
			Bow
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		eDirection GetDirection() { return mDirection; }
	private:
		void Idle();
		void Walk();
		void Roll();
		void Attack1();
		void Attack2();
		void ShortSword();
		void Shield();
		void ShieldWalk();
		void Glove();
		void GloveShot();
		void Death();
		void UsePendant();

		void AnimationIdle();
		void AnimationWalk();
		void AnimationRoll();
		void AnimationShieldOff();
		void AnimationDeath();
		void AnimationPandent();
		void AnimationAttack1();
		void AnimationAttack2();
		void AnimationAttack2Shot();

		void CheckShieldMove();

	private:
		eState mState;
		eDirection mDirection;
		eDirection mFocusDirection;
		eWeapon mWeapon;
		class Animator* mAnimator;
		bool mb_Complete;
		bool mb_Shield;
	};
}

