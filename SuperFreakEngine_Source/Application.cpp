#include "CommonInclude.h"


SF::Application::Application() {
	mHdc = nullptr;
	mHwnd = nullptr;
}

SF::Application::~Application() {}

void SF::Application::Initialize(HWND hwnd) 
{
	mHwnd = hwnd;
	mHdc = GetDC(hwnd);
	mon.SetPosition(0, 0);
}
void SF::Application::Run() 
{
	Update();
	LateUpdate();
	Render();
}
void SF::Application::Update() 
{
	mon.Update();
}
void SF::Application::LateUpdate() 
{

}
void SF::Application::Render() 
{
	mon.Render(mHdc);
}