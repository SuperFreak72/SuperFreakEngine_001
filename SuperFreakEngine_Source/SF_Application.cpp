#include "SF_Application.h"
#include "SF_Input.h"
#include "SF_Time.h"
#include "SF_SceneManager.h"

namespace SF {
	Application::Application() {
		mHdc = nullptr;
		mHwnd = nullptr;
		mWidth = 0;
		mHeight = 0;
		mBackHdc = NULL;
		mBackBuffer = NULL;
	}

	Application::~Application() { }

	void Application::Initialize(HWND hwnd, UINT width, UINT height) {
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initializeEtc();

		
		SceneManager::Initialize();
	}

	void Application::Run() {
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update() {
		Input::Update();
		Time::Update();

		SceneManager::Update();
	}
	void Application::LateUpdate() { }
	void Application::Render() {
		clearRenderTarget();

		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
	}

	void Application::clearRenderTarget() {
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void Application::copyRenderTarget(HDC source, HDC dest) {
		BitBlt(mHdc, 0, 0, mWidth, mHeight,
			mBackHdc, 0, 0, SRCCOPY);
	}

	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height) {
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0,0,width,height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);
		ShowWindow(mHwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height) {
		//윈도우 해상도에 맞는 백버퍼 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		//백버퍼를 가르킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);
	}

	void Application::initializeEtc() {
		Input::Initailize();
		Time::Initailize();
	}
}