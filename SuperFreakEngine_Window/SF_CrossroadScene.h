#pragma once
#include "..\\SuperFreakEngine_Source\\SF_Scene.h"
#include "..\\SuperFreakEngine_Source\\SF_Animator.h"

namespace SF {
	class CrossroadScene : public Scene {
	public:
		CrossroadScene();
		~CrossroadScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit()  override;

	private:
		class BackGround* bg;
		class Player* player;
		class GameObject* camera;
		class Animator* mAnimator;
		class Camera* cameraComp;
		float bgSize;
		
	};
}

