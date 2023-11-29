#pragma once
#include "..\\SuperFreakEngine_Source\\SF_Resources.h"
#include "..\\SuperFreakEngine_Source\\SF_Texture.h"

namespace SF {
	void LoadResources() {
		Resources::Load<Graphics::Texture>(L"BG", L"..\\Resources\\background_118004.png");
	}
}