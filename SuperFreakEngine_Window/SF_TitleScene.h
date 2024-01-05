#pragma once
#include "..\\SuperFreakEngine_Source\\SF_Scene.h"
#include "..\\SuperFreakEngine_Source\\SF_Animator.h"

namespace SF {
	class TitleScene : public Scene {
	public:
		enum class eMenu {
			NewGame,
			LoadGame,
			Option,
			Exit,
		};


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
		void SelectMenu(int value);
	private:
		class BackGround* backBubble;
		class BackGround* frontBubble;
		class BackGround* leftWall;
		class BackGround* rightWall;
		class BackGround* logo;
		class BackGround* mSelectLeft;
		class BackGround* mSelectRight;
		bool mb_openWall;
		bool mb_chooseButton;
		float mTime;
		float mDoorSpeed;

		eMenu mMenu;
		class Vector2 mSelectMenuDirectionL[4];
		class Vector2 mSelectMenuDirectionR[4];
	};
}

