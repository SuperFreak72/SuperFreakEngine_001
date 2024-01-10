#include "SF_WeaponCollision.h"

namespace SF {
	WeaponCollision::WeaponCollision() {
		wWeapon.insert({ L"ShortSword", Vector2(230.0f, 210.0f) });
		wOffset.insert({ L"ShortSwordLeft", Vector2(-102.0f, 0.0f)});
		wOffset.insert({ L"ShortSwordRight", Vector2(0.0f, 0.0f)});
		wOffset.insert({ L"ShortSwordUp", Vector2(-102.0f, -60.0f)});
		wOffset.insert({ L"ShortSwordDown", Vector2(-102.0f, 0.0f)});
	}
	WeaponCollision::~WeaponCollision() {}


	Vector2 WeaponCollision::GetOffset(std::wstring value) {
		for (auto iter = wOffset.begin(); iter != wOffset.end(); iter++)
		{
			if (iter->first == value)
				return iter->second;
		}
		return Vector2::Zero;
	}

	Vector2 WeaponCollision::GetWeapon(std::wstring value) {
		for (auto iter = wWeapon.begin(); iter != wWeapon.end(); iter++)
		{
			if (iter->first == value)
				return iter->second;
		}
		return Vector2::Zero;
	}
}