#pragma once
#include "CommonInclude.h"
#include "SF_Input.h"
#include "SF_Time.h"
#include "SF_Bullet.h"
/*
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
		int flag = 0;
		Bullet* b = nullptr;
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


	//사각형 생성 ( 방향키 움직임 )
	void GameObject1::Update() {
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += speed * Time::DeltaTime();

		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Space)) {
			b = new Bullet();
			b->GetPlayerPos(100.0f + mX, 100.0f + mY, 200.0f + mX, 200.0f + mY);
			flag = 1;
		}

		if (flag == 1)
			b->Update();
	}
	void GameObject1::LateUpdate()
	{

	}
	void GameObject1::Render(HDC hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));


		Rectangle(hdc, 100.0f + mX, 100.0f + mY, 200.0f + mX, 200.0f + mY);
		SelectObject(hdc, oldBrush); // 흰색브러쉬 복원
		DeleteObject(blueBrush); // 파랑 삭제
		DeleteObject(redPen); //빨강 삭제

		if (flag == 1) {
			b->Render(hdc);
			if (b->ShowBulletPosY() < 0.0f) {
				delete b;
				flag = 0;
			}
		}

	}
	void GameObject1::SetPosition(float x, float y)
	{
		mX = x;
		mY = y;
	}

	/*################################################

	// 원 생성 ( WASD 움직임 )
	void GameObject2::Update()
	{
	}
	void GameObject2::LateUpdate()
	{
	}
	void GameObject2::Render(HDC hdc)
	{
		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

		Ellipse(hdc, 300.0f + mX, 300.0f + mY, 400.0f + mX, 400.0f + mY);

		SelectObject(hdc, oldBrush); // 흰색브러쉬 복원
		DeleteObject(redBrush); // 빨강 삭제
	}
	void GameObject2::SetPosition(float x, float y)
	{
		mX = x;
		mY = y;
	}

	/*################################################

	Monster::Monster() {
		randomPos = RandomPos();
		dX = direction[randomPos][0];
		dY = direction[randomPos][1];
		posX = 525.0f;
		posY = 525.0f;
	}

	void Monster::Update()
	{
		if (!((posX >= 25 && posX < 1500) && (posY >= 25 && posY < 850))) {
			ChangePos();
		}
		posX += direction[randomPos][0];
		posY += direction[randomPos][1];
	}
	void Monster::LateUpdate()
	{
	}
	void Monster::Render(HDC hdc)
	{
		HBRUSH YBrush = CreateSolidBrush(RGB(255, 255, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, YBrush);

		Rectangle(hdc, posX - 25, posY - 25, posX + 25, posY + 25); // size is 50

		SelectObject(hdc, oldBrush);
		DeleteObject(YBrush);
	}
	int Monster::RandomPos()
	{
		srand(time(NULL));

		return rand() % 8;
	}
	void Monster::ChangePos()
	{
		if (randomPos == 0) {
			posX += 0.1;
			posY -= 0.1;
			randomPos = rand() % 8;
			if (randomPos == 0)
				randomPos++;
		}
		else if (randomPos == 1) {
			posY -= 0.1;
			randomPos = rand() % 8;
			if (randomPos == 1)
				randomPos++;
		}
		else if (randomPos == 2) {
			posX -= 0.1;
			posY -= 0.1;
			randomPos = rand() % 8;
			if (randomPos == 2)
				randomPos = 7;
		}
		else if (randomPos == 3) {
			posX += 0.1;
			randomPos = rand() % 8;
			if (randomPos == 3)
				randomPos--;

		}
		else if (randomPos == 4) {
			posX -= 0.1;
			randomPos = rand() % 8;
			if (randomPos == 4)
				randomPos++;

		}
		else if (randomPos == 5) {
			posX += 0.1;
			posY += 0.1;
			randomPos = rand() % 8;
			if (randomPos == 5)
				randomPos = 0;

		}
		else if (randomPos == 6) {
			posY += 0.1;
			randomPos = rand() % 8;
			if (randomPos == 6)
				randomPos++;

		}
		else if (randomPos == 7) {
			posX -= 0.1;
			posY += 0.1;
			randomPos = rand() % 8;
			if (randomPos == 7)
				randomPos--;
		}


	}
	void Monster::SetPosition(float x, float y)
	{

	}
}
*/