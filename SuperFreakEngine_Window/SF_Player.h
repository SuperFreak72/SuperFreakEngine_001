#pragma once
#include "..\\SuperFreakEngine_Source\\SF_GameObject.h"

namespace SF {
	class Player: public GameObject{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}

