#pragma once
#include "..\\SuperFreakEngine_Source\\SF_Scene.h"
#include "..\\SuperFreakEngine_Source\\SF_Animator.h"

namespace SF {
	class PlayScene : public Scene{
	public:
		
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit()  override;

		
	private:
		void CheckPlayerState();
		void ChangeCollistionByState();
		void BuildWallCollider();
	private:
		class BackGround* bg;
		class Player* player;
		class Monster* monster;
		class GameObject* camera;
		float bgSize;
	};
}

