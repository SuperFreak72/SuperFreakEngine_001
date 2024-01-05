#pragma once
#include "..\\SuperFreakEngine_Source\\SF_Scene.h"
#include "..\\SuperFreakEngine_Source\\SF_Animator.h"

#include <new>
#include <windows.h>
#include <windowsx.h>
#include <mfplay.h>
#include <mferror.h>
#include <shobjidl.h>
#include <strsafe.h>
#include <Shlwapi.h>
#include <mfplay.h>
#include "..\SuperFreakEngine_Source\SF_Application.h"

namespace SF {
	class VideoScene : public Scene{
	public:
		VideoScene();
		~VideoScene();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit()  override;

	private:
		HRESULT PlayVideo(HWND hwnd, const WCHAR* sURL);
	private:
		float mTime;
		const WCHAR* sURL = L"..\\Resources\\testVideo.wmv";
		IMFPMediaPlayer* g_pPlayer = NULL;
	};
}

