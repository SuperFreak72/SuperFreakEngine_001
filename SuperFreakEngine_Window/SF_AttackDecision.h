#pragma once
#include "..\\SuperFreakEngine_Source\\SF_GameObject.h"
#include "..\\SuperFreakEngine_Source\\SF_PlayerScript.h"
#include "SF_Player.h"

namespace SF {
	class AttackDecision : public GameObject {
	public:
		AttackDecision();
		~AttackDecision();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTarget(Player* value) { tPlayer = value; }

	private:
		void AddDecision();
		Vector2 FindOffset(std::wstring value);
		Vector2 FindWeapon(std::wstring value);
		void CheckWeapon();

		void SetRangeShortSword();
		void SetRangeBigSword();
		void SetRangeSpear();
		void SetRangeGlove();
		void SetRangeBow();

	private:
		Player* tPlayer;
		Vector2 mPos;
		Vector2 mAttackRange;
		std::map<std::wstring, Vector2> wOffset;
		std::map<std::wstring, Vector2> wWeapon;
		PlayerScript::eDirection mDirection;
		PlayerScript::eWeapon mWeapon;
		bool mb_orderCheck;
	};
}

