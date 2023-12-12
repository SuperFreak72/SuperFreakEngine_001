#pragma once
#include "SF_Collider.h"

namespace SF {
	class BoxCollider2D : public Collider {
	public:
		BoxCollider2D();
		~BoxCollider2D();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	private:
	};
}

