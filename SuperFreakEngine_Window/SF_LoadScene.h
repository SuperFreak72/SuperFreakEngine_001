#pragma once
#include "..\\SuperFreakEngine_Source\\SF_SceneManager.h"

#include "SF_PlayScene.h"
#include "SF_TitleScene.h"
#include "SF_VideoScene.h"
#include "SF_CrossroadScene.h"

namespace SF {

	void LoadScenes() {
		//SceneManager::CreateScene<VideoScene>(L"VideoScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<CrossroadScene>(L"CrossroadScene");
		

		//SceneManager::LoadScene(L"VideoScene");
		SceneManager::LoadScene(L"PlayScene");
	}
}
