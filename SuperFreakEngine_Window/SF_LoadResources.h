#pragma once
#include "..\\SuperFreakEngine_Source\\SF_Resources.h"
#include "..\\SuperFreakEngine_Source\\SF_Texture.h"

namespace SF {
	void LoadResources() {
		Resources::Load<Graphics::Texture>(L"BG", L"..\\Resources\\Village_Background_Alpha.bmp");
		Resources::Load<Graphics::Texture>(L"PlayerMotion", L"..\\Resources\\Will_Cycle_Motion_128x128_Alpha.bmp");
		Resources::Load<Graphics::Texture>(L"PlayerAttack_SSG", L"..\\Resources\\Will_Cycle_Attack_Short_Shield_Gloves_128x128_Alpha.bmp"); //ShortSword, Shield, Gloves Motions
		
	}
}