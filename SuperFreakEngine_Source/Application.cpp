#include "CommonInclude.h"
#include "SFInput.h"


SF::Application::Application() {
	mHdc = nullptr;
	mHwnd = nullptr;
}

SF::Application::~Application() {}

void SF::Application::Initialize(HWND hwnd) 
{
	mHwnd = hwnd;
	mHdc = GetDC(hwnd);
	ob1.SetPosition(0, 0);
	Input::Initailize();
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
	ob1.Update();
}
void SF::Application::LateUpdate() 
{

}
void SF::Application::Render() 
{
	ob1.Render(mHdc);
}