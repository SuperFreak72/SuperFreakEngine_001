#include "SF_AttackDecision.h"
#include "SF_PlayerScript.h"
#include "SF_Camera.h"
#include "SF_Renderer.h"
#include "SF_Input.h"
#include "SF_Transform.h"
#include "SF_Time.h"
#include "SF_BoxCollider2D.h"

namespace SF {
	AttackDecision::AttackDecision() 
	: tPlayer(nullptr)
	, mPos(Vector2::Zero)
	, mAttackRange(Vector2::Zero)
	, mb_orderCheck(false)
	{}
	AttackDecision::~AttackDecision() {}
	void AttackDecision::Initialize() {
		AddDecision();
		GameObject::Initialize();
	}
	void AttackDecision::Update() {
		if (tPlayer->GetComponent<PlayerScript>()->GetAttack() && !mb_orderCheck) {
			CheckWeapon();
			mb_orderCheck = true;
		}
		else if (!tPlayer->GetComponent<PlayerScript>()->GetAttack() && mb_orderCheck) {
			mb_orderCheck = false;
		}

		GameObject::Update();
	}
	void AttackDecision::LateUpdate() {
		GameObject::LateUpdate();
	}
	void AttackDecision::Render(HDC hdc) {
		if (tPlayer == nullptr) {
			return;
		}
		if (tPlayer->GetComponent<PlayerScript>()->GetAttack()) {
			Transform* trPlayer = tPlayer->GetComponent<Transform>();
			Transform* tr = this->GetComponent<Transform>();
			Vector2 pos = Renderer::mainCamera->CaluatePosition(trPlayer->GetPosition());
			HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255));
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

			Vector2 setPos = Vector2(pos.x + mPos.x, pos.y + mPos.y);

			Rectangle(hdc
				, pos.x + mPos.x
				, pos.y + mPos.y
				, pos.x + mAttackRange.x
				, pos.y + mAttackRange.y);

			SelectObject(hdc, oldBrush);
			DeleteObject(myBrush);

			tr->SetPosition(setPos);
		}
		else {
			GameObject::Render(hdc);
		}
	}

	void AttackDecision::AddDecision() {
		wWeapon.insert({ L"ShortSword", Vector2(230.0f, 210.0f) });
		wOffset.insert({ L"ShortSwordLeft", Vector2(-102.0f, 0.0f) });
		wOffset.insert({ L"ShortSwordRight", Vector2(0.0f, 0.0f) });
		wOffset.insert({ L"ShortSwordUp", Vector2(-102.0f, -60.0f) });
		wOffset.insert({ L"ShortSwordDown", Vector2(-102.0f, 0.0f) });

		wWeapon.insert({ L"BigSword", Vector2(230.0f, 210.0f) });
		wOffset.insert({ L"BigSwordLeft", Vector2(-102.0f, 0.0f) });
		wOffset.insert({ L"BigSwordRight", Vector2(0.0f, 0.0f) });
		wOffset.insert({ L"BigSwordUp", Vector2(-102.0f, -60.0f) });
		wOffset.insert({ L"BigSwordDown", Vector2(-102.0f, 0.0f) });

		wWeapon.insert({ L"Spear", Vector2(230.0f, 210.0f) });
		wOffset.insert({ L"SpearLeft", Vector2(-102.0f, 0.0f) });
		wOffset.insert({ L"SpearRight", Vector2(0.0f, 0.0f) });
		wOffset.insert({ L"SpearUp", Vector2(-102.0f, -60.0f) });
		wOffset.insert({ L"SpearDown", Vector2(-102.0f, 0.0f) });

		wWeapon.insert({ L"Glove", Vector2(230.0f, 210.0f) });
		wOffset.insert({ L"GloveLeft", Vector2(-102.0f, 0.0f) });
		wOffset.insert({ L"GloveRight", Vector2(0.0f, 0.0f) });
		wOffset.insert({ L"GloveUp", Vector2(-102.0f, -60.0f) });
		wOffset.insert({ L"GloveDown", Vector2(-102.0f, 0.0f) });

		wWeapon.insert({ L"Bow", Vector2(230.0f, 210.0f) });
		wOffset.insert({ L"BowLeft", Vector2(-102.0f, 0.0f) });
		wOffset.insert({ L"BowRight", Vector2(0.0f, 0.0f) });
		wOffset.insert({ L"BowUp", Vector2(-102.0f, -60.0f) });
		wOffset.insert({ L"BowDown", Vector2(-102.0f, 0.0f) });
	}

	Vector2 AttackDecision::FindOffset(std::wstring value) {
		for (auto iter = wOffset.begin(); iter != wOffset.end(); iter++)
		{
			if (iter->first == value)
				return iter->second;
		}
		return Vector2::Zero;
	}

	Vector2 AttackDecision::FindWeapon(std::wstring value){
		for (auto iter = wWeapon.begin(); iter != wOffset.end(); iter++)
		{
			if (iter->first == value)
				return iter->second;
		}
		return Vector2::Zero;
	}

	void AttackDecision::CheckWeapon() {
		mWeapon = tPlayer->GetComponent<PlayerScript>()->GetWeapon();
		switch (mWeapon) {
		case SF::PlayerScript::eWeapon::ShortSword:
			SetRangeShortSword();
			break;
		case SF::PlayerScript::eWeapon::Gloves:
			SetRangeGlove();
			break;
		case SF::PlayerScript::eWeapon::BigSword:
			SetRangeBigSword();
			break;
		case SF::PlayerScript::eWeapon::Spear:
			SetRangeSpear();
			break;
		case SF::PlayerScript::eWeapon::Bow:
			SetRangeBow();
			break;
		default:
			assert(false);
			break;
		}
	}

	void AttackDecision::SetRangeShortSword() {
		mDirection = tPlayer->GetComponent<PlayerScript>()->GetDirection();

		switch (mDirection) {
		case SF::PlayerScript::eDirection::Left:
			mPos = FindOffset(L"ShortSwordLeft");
			break;
		case SF::PlayerScript::eDirection::Right:
			mPos = FindOffset(L"ShortSwordRight");
			break;
		case SF::PlayerScript::eDirection::Down:
			mPos = FindOffset(L"ShortSwordDown");
			break;
		case SF::PlayerScript::eDirection::Up:
			mPos = FindOffset(L"ShortSwordUp");
			break;
		case SF::PlayerScript::eDirection::End:
			break;
		default:
			break;
		}
	}
	void AttackDecision::SetRangeBigSword() {
		mDirection = tPlayer->GetComponent<PlayerScript>()->GetDirection();

		switch (mDirection) {
		case SF::PlayerScript::eDirection::Left:
			mPos = FindOffset(L"BigSwordLeft");
			break;
		case SF::PlayerScript::eDirection::Right:
			mPos = FindOffset(L"BigSwordRight");
			break;
		case SF::PlayerScript::eDirection::Down:
			mPos = FindOffset(L"BigSwordDown");
			break;
		case SF::PlayerScript::eDirection::Up:
			mPos = FindOffset(L"BigSwordUp");
			break;
		case SF::PlayerScript::eDirection::End:
			break;
		default:
			break;
		}
	}
	void AttackDecision::SetRangeSpear() {
		mDirection = tPlayer->GetComponent<PlayerScript>()->GetDirection();

		switch (mDirection) {
		case SF::PlayerScript::eDirection::Left:
			mPos = FindOffset(L"SpearLeft");
			break;
		case SF::PlayerScript::eDirection::Right:
			mPos = FindOffset(L"SpearRight");
			break;
		case SF::PlayerScript::eDirection::Down:
			mPos = FindOffset(L"SpearDown");
			break;
		case SF::PlayerScript::eDirection::Up:
			mPos = FindOffset(L"SpearUp");
			break;
		case SF::PlayerScript::eDirection::End:
			break;
		default:
			break;
		}
	}
	void AttackDecision::SetRangeGlove() {
		mDirection = tPlayer->GetComponent<PlayerScript>()->GetDirection();

		switch (mDirection) {
		case SF::PlayerScript::eDirection::Left:
			mPos = FindOffset(L"GloveLeft");
			break;
		case SF::PlayerScript::eDirection::Right:
			mPos = FindOffset(L"GloveRight");
			break;
		case SF::PlayerScript::eDirection::Down:
			mPos = FindOffset(L"GloveDown");
			break;
		case SF::PlayerScript::eDirection::Up:
			mPos = FindOffset(L"GloveUp");
			break;
		case SF::PlayerScript::eDirection::End:
			break;
		default:
			break;
		}
	}
	void AttackDecision::SetRangeBow() {
		mDirection = tPlayer->GetComponent<PlayerScript>()->GetDirection();

		switch (mDirection) {
		case SF::PlayerScript::eDirection::Left:
			mPos = FindOffset(L"BowLeft");
			break;
		case SF::PlayerScript::eDirection::Right:
			mPos = FindOffset(L"BowRight");
			break;
		case SF::PlayerScript::eDirection::Down:
			mPos = FindOffset(L"BowDown");
			break;
		case SF::PlayerScript::eDirection::Up:
			mPos = FindOffset(L"BowUp");
			break;
		case SF::PlayerScript::eDirection::End:
			break;
		default:
			break;
		}
	}
}