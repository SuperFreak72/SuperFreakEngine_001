#include "SFApplication.h"
#include "CommonInclude.h"

SF::Application::Application() {
	mSpeed = 0;
	mHdc = nullptr;
	mHwnd = nullptr;
	mX = 0.0f;
	mY = 0.0f;
}

SF::Application::~Application() {}

void SF::Application::Initialize(HWND hwnd) 
{
	mHwnd = hwnd;
	mHdc = GetDC(hwnd);
}
void SF::Application::Run() 
{
	Update();
	LateUpdate();
	Render();
}
void SF::Application::Update() 
{
	mSpeed += 0.005f;

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
void SF::Application::LateUpdate() 
{

}
void SF::Application::Render() 
{
	HBRUSH blueBrush = CreateSolidBrush(RGB(0,0,255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush);

	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);
	SelectObject(mHdc, oldPen);

	Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

	SelectObject(mHdc, oldBrush); // 흰색브러쉬 복원
	DeleteObject(blueBrush); // 파랑 삭제
	DeleteObject(redPen);
}