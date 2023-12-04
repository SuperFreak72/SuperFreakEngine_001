#pragma once
#include "..\\SuperFreakEngine_Source\\SF_Resources.h"
#include "..\\SuperFreakEngine_Source\\SF_Texture.h"

namespace SF {
	void LoadResources() {
		Resources::Load<Graphics::Texture>(L"BG", L"..\\Resources\\VillageEnvironment.png");
		Resources::Load<Graphics::Texture>(L"PlayerWalk", L"..\\Resources\\Will_Walk_Roll_GrassWalk_Alpha.bmp");
		Resources::Load<Graphics::Texture>(L"PlayerIdle", L"..\\Resources\\Will_Idle_GrassIdle_Alpha.bmp");
		Resources::Load<Graphics::Texture>(L"PlayerGlove", L"..\\Resources\\Will_Gloves_Attack_Alpha.bmp");
	}
}