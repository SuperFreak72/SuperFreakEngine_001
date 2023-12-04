#pragma once
#include "..\\SuperFreakEngine_Source\\SF_Scene.h"

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

		void AnimationLoad();
	private:
		class Player* bg;
	};
}

