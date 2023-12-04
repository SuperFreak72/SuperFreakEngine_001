#pragma once
#include "SF_Entity.h"
#include "SF_Component.h"

namespace SF {
	using namespace SF::math;
	class Camera : public Component{
	public:
		 Vector2 CaluatePosition(Vector2 pos) {
			 return pos;
		};

		Camera();
		~Camera();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;


	private:
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;
		GameObject* mTarget;
	};
}

