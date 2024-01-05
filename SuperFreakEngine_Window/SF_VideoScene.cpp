#include "SF_VideoScene.h"
#include "SF_Input.h"
#include "SF_SceneManager.h"
#include "SF_Renderer.h"


extern SF::Application app;

namespace SF{
	VideoScene::VideoScene()
	: mTime(0.0f)
	{}
	
	VideoScene::~VideoScene() {}

	void VideoScene::Initialize() {
		PlayVideo(app.GetHwnd(), sURL);
	}

	void VideoScene::Update()
	{
	}
	void VideoScene::LateUpdate()
	{
	}
	void VideoScene::Render(HDC hdc)
	{
	}
	void VideoScene::OnEnter()
	{
	}
	void VideoScene::OnExit() {
		
	}
	HRESULT VideoScene::PlayVideo(HWND hwnd, const WCHAR* sURL) {
		return MFPCreateMediaPlayer(
			sURL,
			TRUE,   // Start playback automatically?
			0,      // Flags.
			NULL,   // Callback pointer.
			hwnd,
			&g_pPlayer
		);
	}
}