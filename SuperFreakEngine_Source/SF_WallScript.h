#pragma once
#include "SF_Script.h"
#include "SF_Transform.h"

namespace SF {
	class WallScript : public Script {
	public:
		WallScript();
		~WallScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;
	private:

	};
}

