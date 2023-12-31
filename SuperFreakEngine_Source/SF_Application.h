#pragma once
#include "SF_GameObject.h"

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
		void Destroy();
		void Release();

		HDC GetHdc() {
			return mHdc;
		}
		UINT GetWidth() {
			return mWidth;
		}
		UINT GetHeight() {
			return mHeight;
		}
		HWND GetHwnd() {
			return mHwnd;
		}

	private:
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;
	};
}

