#include "CommonInclude.h"

//사각형 생성 ( 방향키 움직임 )
void SF::GameObject1::Update()
{
	if (GetAsyncKeyState(VK_LEFT)) {
		mX -= 0.01f;
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		mX += 0.01f;
	}
	if (GetAsyncKeyState(VK_UP)) {
		mY -= 0.01f;
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		mY += 0.01f;
	}
}
void SF::GameObject1::LateUpdate()
{
}
void SF::GameObject1::Render(HDC hdc)
{
	HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));


	Rectangle(hdc, 100.0f + mX, 100.0f + mY, 200.0f + mX, 200.0f + mY);

	SelectObject(hdc, oldBrush); // 흰색브러쉬 복원
	DeleteObject(blueBrush); // 파랑 삭제
	DeleteObject(redPen); //빨강 삭제
}
void SF::GameObject1::SetPosition(float x, float y)
{
	mX = x;
	mY = y;
}


/*################################################*/
// 원 생성 ( WASD 움직임 )
void SF::GameObject2::Update()
{
	if (GetAsyncKeyState('A')) {
		mX -= 0.01f;
	}
	if (GetAsyncKeyState('D')) {
		mX += 0.01f;
	}
	if (GetAsyncKeyState('W')) {
		mY -= 0.01f;
	}
	if (GetAsyncKeyState('S')) {
		mY += 0.01f;
	}
}
void SF::GameObject2::LateUpdate()
{
}
void SF::GameObject2::Render(HDC hdc)
{
	HBRUSH redBrush = CreateSolidBrush(RGB(255,0,0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

	Ellipse(hdc, 300.0f + mX, 300.0f + mY, 400.0f + mX, 400.0f + mY);

	SelectObject(hdc, oldBrush); // 흰색브러쉬 복원
	DeleteObject(redBrush); // 빨강 삭제
}
void SF::GameObject2::SetPosition(float x, float y)
{
	mX = x;
	mY = y;
}


