#pragma once
#include "..\\SuperFreakEngine_Source\\SF_SceneManager.h"

#include "SF_PlayScene.h"

namespace SF {

	void LoadScenes() {
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
		
	}
}
