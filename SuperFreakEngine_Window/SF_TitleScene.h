#pragma once
#include "..\\SuperFreakEngine_Source\\SF_Scene.h"
#include "..\\SuperFreakEngine_Source\\SF_Animator.h"

namespace SF {
	class TitleScene : public Scene {
	public:
		TitleScene();
		~TitleScene();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit()  override;
	private:
		void LoadAnimationBackBubble(Animator* value);
		void LoadAnimationFrontBubble(Animator* value);
		void AnimationOpenWall();
	private:
		class BackGround* backBubble;
		class BackGround* frontBubble;
		class BackGround* leftWall;
		class BackGround* rightWall;
		class BackGround* logo;
		class BackGround* light;
		bool mb_openWall = false;
		float mTime;
		float mDoorSpeed;
	};
}

