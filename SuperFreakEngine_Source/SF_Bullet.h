#pragma once
#include "CommonInclude.h"

namespace SF {
	class Bullet
	{
	public:
		Bullet();
		~Bullet();

		void Update();
		void Render(HDC hdc);
		void GetPlayerPos(float pL, float pT, float pR, float pB);
		float ShowBulletPosX() {
			return  (pL + pT + 2 * bX) / 2;
		}
		float ShowBulletPosY() {
			return (pR + pB + 2 * bY) / 2;
		}
	private:
		float pL, pT, pR, pB;
		float bX, bY;
		float speed;
	};
}



