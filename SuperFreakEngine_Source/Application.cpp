#include "CommonInclude.h"


SF::Application::Application() {
	mSpeed = 0;
	mHdc = nullptr;
	mHwnd = nullptr;
}

SF::Application::~Application() {}

void SF::Application::Initialize(HWND hwnd) 
{
	mHwnd = hwnd;
	mHdc = GetDC(hwnd);
	rec.SetPosition(0, 0);
	ell.SetPosition(0, 0);
}
void SF::Application::Run() 
{
	Update();
	LateUpdate();
	Render();
}
void SF::Application::Update() 
{
	rec.Update();
	ell.Update();
}
void SF::Application::LateUpdate() 
{

}
void SF::Application::Render() 
{
	rec.Render(mHdc);
	ell.Render(mHdc);
}