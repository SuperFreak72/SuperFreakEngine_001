#pragma once
#include "CommonInclude.h"

namespace SF {
	class Application
	{
	public:
		Application();
		~Application();
		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();
	private:
		HWND mHwnd;
		HDC mHdc;
		GameObject1 ob1;
	};
}

