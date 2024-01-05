#pragma once
#include "..\\SuperFreakEngine_Source\\SF_Resources.h"
#include "..\\SuperFreakEngine_Source\\SF_Texture.h"

namespace SF {
	void LoadResources() {
		Resources::Load<Graphics::Texture>(L"TitleBubble", L"..\\Resources\\Title_Bubble_Alpha.bmp");
		Resources::Load<Graphics::Texture>(L"LeftWall", L"..\\Resources\\Title_Wall_Left_319x370.bmp");
		Resources::Load<Graphics::Texture>(L"RightWall", L"..\\Resources\\Title_Wall_Right_319x370.bmp");
		Resources::Load<Graphics::Texture>(L"Logo", L"..\\Resources\\Title_Logo_Alpha.bmp");
		Resources::Load<Graphics::Texture>(L"UI_SelectL", L"..\\Resources\\UI_SelectL_Alpha.bmp");
		Resources::Load<Graphics::Texture>(L"UI_SelectR", L"..\\Resources\\UI_SelectR_Alpha.bmp");
		
		
		
		Resources::Load<Graphics::Texture>(L"BG", L"..\\Resources\\Village_Background_Alpha.bmp");
		Resources::Load<Graphics::Texture>(L"PlayerMotion1", L"..\\Resources\\Will_Cycle_Motion_128x128_Alpha.bmp");
		Resources::Load<Graphics::Texture>(L"PlayerMotion", L"..\\Resources\\Will_Cycle_Motion_128x128_Alpha2.bmp");
		Resources::Load<Graphics::Texture>(L"PlayerAttack_SS", L"..\\Resources\\Will_Cycle_Attack_Short_Shield_128x128_Alpha.bmp");
		Resources::Load<Graphics::Texture>(L"PlayerAttack_G", L"..\\Resources\\Will_Cycle_Attack_Gloves_128x128_Alpha.bmp");
		Resources::Load<Graphics::Texture>(L"PlayerAttack_BS", L"..\\Resources\\Will_Cycle_Attack_BigSword_256x256_Alpha.bmp");
		Resources::Load<Graphics::Texture>(L"PlayerAttack_S", L"..\\Resources\\Will_Cycle_Attack_Spear_256x256_Alpha.bmp");
		Resources::Load<Graphics::Texture>(L"PlayerAttack_B", L"..\\Resources\\Will_Cycle_Attack_Bow_128x128_Alpha.bmp");
		
		
		
		Resources::Load<Graphics::Texture>(L"Entrance", L"..\\Resources\\DungeonsEntrance_Alpha.bmp");
	}
}