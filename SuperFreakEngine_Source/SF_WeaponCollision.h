#pragma once
#include "CommonInclude.h"
#include "SF_PlayerScript.h"
#include "SF_Entity.h"
#include <SF_Math.h>
#include <string>

using namespace SF::math;

namespace SF {
	class WeaponCollision : public Entity {
	public:
		enum class eWeapon {
			ShortSword,
			Glove,
			BigSword,
			Spear,
			Bow
		};

		WeaponCollision();
		~WeaponCollision();
		
		Vector2 GetOffset(std::wstring value);
		Vector2 GetWeapon(std::wstring value);
	private:
		std::map<std::wstring, Vector2> wOffset;
		std::map<std::wstring, Vector2> wWeapon;
	};
}

