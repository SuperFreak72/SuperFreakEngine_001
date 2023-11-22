#pragma once
#include "..\\SuperFreakEngine_Source\\SF_Scene.h"

namespace SF {
	class VillageScene : public Scene {
	public:
		VillageScene();
		~VillageScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit()  override;
	private:
		class Player* bg;
	};
}

