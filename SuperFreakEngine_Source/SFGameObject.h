#pragma once
#include "CommonInclude.h"

namespace SF {
	class GameObject1 {
	public:
		GameObject1() { mX = 0.0f, mY = 0.0f; };
		~GameObject1() {};
		void Update();
		void LateUpdate();
		void Render(HDC hdc);
		void SetPosition(float x, float y);
	private:
		float mX;
		float mY;
	};

	class GameObject2 {
	public:
		GameObject2() { mX = 0.0f, mY = 0.0f; };
		~GameObject2() {};
		void Update();
		void LateUpdate();
		void Render(HDC hdc);
		void SetPosition(float x, float y);
	private:
		float mX;
		float mY;
	};

	class Monster {
	public:
		Monster();
		~Monster() {};
		void Update();
		void LateUpdate();
		void Render(HDC hdc);
		int RandomPos();
		void SetPosition(float x, float y);
		void ChangePos();
	private:
		float direction[8][2] = {
			{-0.007f,+0.007f}, // 좌하단[1]
			{+0.000f,+0.007f}, // 하단[2]
			{+0.007f,+0.007f}, // 우하단[3]
			{-0.007f,+0.000f}, // 좌[4]
			{+0.007f,+0.000f}, // 우[6]
			{-0.007f,-0.007f}, // 좌상단[7]
			{+0.000f,-0.007f}, // 상[8]
			{+0.007f,-0.007f}, // 우상단[9]
		};
		int randomPos;
		float dX;
		float dY;
		float posX;
		float posY;
	};
}