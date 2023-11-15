#pragma once
#include "CommonInclude.h"
#include "SF_Input.h"
#include "SF_Time.h"
#include "SF_Bullet.h"

namespace SF {
	class GameObject {
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }


	private:
		float mX;
		float mY;
	};
}