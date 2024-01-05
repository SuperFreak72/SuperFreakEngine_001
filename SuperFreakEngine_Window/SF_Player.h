#pragma once
#include "..\\SuperFreakEngine_Source\\SF_GameObject.h"
#include "..\\SuperFreakEngine_Source\\SF_Animator.h"

namespace SF {
	class Player: public GameObject{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
		void AnimationLoad();
		void LoadAnimationIdle(Animator* playerAnimator);
		void LoadAnimationWalk(Animator* playerAnimator);
		void LoadAnimationRoll(Animator* playerAnimator);
		void LoadAniamtionSwim(Animator* playerAnimator);
		void LoadAnimationGrassIdle(Animator* playerAnimator);
		void LoadAnimationGrassWalk(Animator* playerAnimator);
		void LoadAnimationDeath(Animator* playerAnimator);
		void LoadAnimationPendant(Animator* playerAnimator);
		void LoadAnimationShortSword(Animator* playerAnimator);
		void LoadAnimationShield(Animator* playerAnimator);
		void LoadAnimationGloves(Animator* playerAnimator);
		void LoadAnimationBigSword(Animator* playerAnimator);
		void LoadAnimationSpear(Animator* playerAnimator);
		void LoadAnimationBow(Animator* playerAnimator);
	};
}

