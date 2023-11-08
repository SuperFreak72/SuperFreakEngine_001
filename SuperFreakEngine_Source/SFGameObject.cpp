#include "CommonInclude.h"

//�簢�� ���� ( ����Ű ������ )
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

	SelectObject(hdc, oldBrush); // ����귯�� ����
	DeleteObject(blueBrush); // �Ķ� ����
	DeleteObject(redPen); //���� ����
}
void SF::GameObject1::SetPosition(float x, float y)
{
	mX = x;
	mY = y;
}


/*################################################*/
// �� ���� ( WASD ������ )
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

	SelectObject(hdc, oldBrush); // ����귯�� ����
	DeleteObject(redBrush); // ���� ����
}
void SF::GameObject2::SetPosition(float x, float y)
{
	mX = x;
	mY = y;
}


