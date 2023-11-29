#pragma once
#include "..\\SuperFreakEngine_Source\\SF_SceneManager.h"

#include "SF_PlayScene.h"
#include "SF_HomeScene.h"
#include "SF_VillageScene.h"

namespace SF {

	void LoadScenes() {
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<VillageScene>(L"VillageScene");
		SceneManager::CreateScene<HomeScene>(L"HomeScene");

		SceneManager::LoadScene(L"PlayScene");
		
	}
}
