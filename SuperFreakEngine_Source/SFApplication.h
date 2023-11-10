#pragma once
#include "CommonInclude.h"

namespace SF {
	class Application
	{
	public:
		Application();
		~Application();
		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBuffer;

		GameObject1 ob1;
		UINT mWidth;
		UINT mHeight;
	};
}

