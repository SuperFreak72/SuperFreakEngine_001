#pragma once
#include "..\\SuperFreakEngine_Source\\SF_SceneManager.h"

#include "SF_PlayScene.h"
#include "SF_TitleScene.h"

namespace SF {

	void LoadScenes() {
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"TitleScene");
	}
}
