#include "CommonInclude.h"
#include "SFInput.h"
#include "SFTime.h"


SF::Application::Application() {
	mHdc = nullptr;
	mHwnd = nullptr;
	mWidth = 0;
	mHeight = 0;
	mBackHdc = nullptr;
	mBackBuffer = nullptr;
}

SF::Application::~Application() {}

void SF::Application::Initialize(HWND hwnd, UINT width, UINT height) 
{
	mHwnd = hwnd;
	mHdc = GetDC(hwnd);

	RECT rect = {0,0,width,height};
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	mWidth = rect.right - rect.left;
	mHeight = rect.bottom - rect.top;

	SetWindowPos(mHwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);
	ShowWindow(mHwnd, true);

	//윈도우 해상도에 맞는 백버퍼 생성
	mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

	//백버퍼를 가르킬 DC생성
	mBackHdc = CreateCompatibleDC(mHdc);
	HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
	DeleteObject(oldBitmap);

	ob1.SetPosition(0, 0);
	Input::Initailize();
	Time::Initailize();
}

void SF::Application::Run() 
{
	Update();
	LateUpdate();
	Render();
}
void SF::Application::Update() 
{
	Input::Update();
	Time::Update();
	ob1.Update();
}
void SF::Application::LateUpdate() 
{

}
void SF::Application::Render() 
{
	Rectangle(mBackHdc, 0, 0, 1600, 900);

	Time::Render(mBackHdc);
	ob1.Render(mBackHdc);

	BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc,0,0,SRCCOPY);
}