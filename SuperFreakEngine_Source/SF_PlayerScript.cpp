#include "SF_PlayerScript.h"
#include "SF_Input.h"
#include "SF_Transform.h"
#include "SF_Time.h"
#include "SF_GameObject.h"
#include "SF_Animator.h"
#include "SF_Object.h"
#include "SF_Resources.h"

namespace SF {
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, mDirection(PlayerScript::eDirection::Down)
		, mFocusDirection(PlayerScript::eDirection::Down)
		, mWeapon(PlayerScript::eWeapon::ShortSword)
		, mAnimator(nullptr)
		, mb_Complete(true)
		, mb_Shield(false)
	{}
	PlayerScript::~PlayerScript() {}
	
	void PlayerScript::Initialize() {}

	void PlayerScript::Update() {
		if (mAnimator == nullptr) {
			mAnimator = GetOwner()->GetComponent<Animator>();
		}
		switch (mState) {
		case SF::PlayerScript::eState::Idle:
			Idle();
			break;
		case SF::PlayerScript::eState::Walk:
			Walk();
			break;
		case SF::PlayerScript::eState::Roll:
			Roll();
			break;
		case SF::PlayerScript::eState::Attack1:
			Attack1();
			break;
		case SF::PlayerScript::eState::Attack2:
			Attack2();
			break;
		case SF::PlayerScript::eState::Attack2Shot:
			Attack2();
			break;
		case SF::PlayerScript::eState::Attack2Shot2:
			SpearShot2();
			break;
		case SF::PlayerScript::eState::Death:
			Death();
			break;
		case SF::PlayerScript::eState::Pendant:
			UsePendant();
			break;
		default:
			break;
		}
	}

	void PlayerScript::LateUpdate() {}

	void PlayerScript::Render(HDC hdc) {}

	void PlayerScript::OnCollisionEnter(Collider* other) {
		int a = 0;
	}

	void PlayerScript::OnCollisionStay(Collider* other)
	{
	}

	void PlayerScript::OnCollisionExit(Collider* other)
	{
	}

	void PlayerScript::Idle() {
		if (Input::GetKey(eKeyCode::D)) //Right Move
		{
			mState = PlayerScript::eState::Walk;
			mDirection = PlayerScript::eDirection::Right;
			mFocusDirection = PlayerScript::eDirection::Right;
			AnimationWalk();
		}
		if (Input::GetKey(eKeyCode::A)) //Left Move
		{
			mState = PlayerScript::eState::Walk;
			mDirection = PlayerScript::eDirection::Left;
			mFocusDirection = PlayerScript::eDirection::Left;
			AnimationWalk();
		}
		if (Input::GetKey(eKeyCode::W)) //Up Move
		{
			mState = PlayerScript::eState::Walk;
			mDirection = PlayerScript::eDirection::Up;
			mFocusDirection = PlayerScript::eDirection::Up;
			AnimationWalk();
		}
		if (Input::GetKey(eKeyCode::S)) //Down Move
		{
			mState = PlayerScript::eState::Walk;
			mDirection = PlayerScript::eDirection::Down;
			mFocusDirection = PlayerScript::eDirection::Down;
			AnimationWalk();
		}
		if (Input::GetKey(eKeyCode::Space)) //Roll
		{
			AnimationRoll();
		}
		if (Input::GetKey(eKeyCode::J))
		{
			AnimationAttack1();
		}
		if (Input::GetKey(eKeyCode::K))
		{
			AnimationAttack2();
		}
		if (Input::GetKey(eKeyCode::O)) { //Death Animation Test
			AnimationDeath();
		}
		if (Input::GetKey(eKeyCode::P)) { //Use Pendant Animation Test

			AnimationPandent();
		}
		if (Input::GetKey(eKeyCode::Two)) {
			mWeapon = PlayerScript::eWeapon::Gloves;
		}
		if (Input::GetKey(eKeyCode::One)) {
			mWeapon = PlayerScript::eWeapon::ShortSword;
		}
		if (Input::GetKey(eKeyCode::Three)) {
			mWeapon = PlayerScript::eWeapon::BigSword;
		}
		if (Input::GetKey(eKeyCode::Four)) {
			mWeapon = PlayerScript::eWeapon::Spear;
		}
	}

	void PlayerScript::Walk() {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::D))
		{
			mDirection = PlayerScript::eDirection::Right;
			mFocusDirection = PlayerScript::eDirection::Right;
			pos.x += 400.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			mDirection = PlayerScript::eDirection::Left; 
			mFocusDirection = PlayerScript::eDirection::Left;
			pos.x -= 400.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::W))
		{
			mDirection = PlayerScript::eDirection::Up;
			mFocusDirection = PlayerScript::eDirection::Up;
			pos.y -= 400.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mDirection = PlayerScript::eDirection::Down;
			mFocusDirection = PlayerScript::eDirection::Down;
			pos.y += 400.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Space)) //Roll
		{
			AnimationRoll();
		}
		if (Input::GetKey(eKeyCode::J))
		{
			AnimationAttack1();
		}
		if (Input::GetKey(eKeyCode::K))
		{
			AnimationAttack2();
		}

		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::D)) {
			AnimationIdle();
		}
		if (Input::GetKeyUp(eKeyCode::A)) {
			AnimationIdle();
		}
		if (Input::GetKeyUp(eKeyCode::W)) {
			AnimationIdle();
		}
		if (Input::GetKeyUp(eKeyCode::S)) {
			AnimationIdle();
		}
	}

	void PlayerScript::Attack1() {
		switch (mWeapon) {
		case PlayerScript::eWeapon::ShortSword:
			ShortSword();
			break;
		case PlayerScript::eWeapon::Gloves:
			Glove();
			break;
		case PlayerScript::eWeapon::BigSword:
			BigSword();
			break;
		case PlayerScript::eWeapon::Spear:
			Spear();
			break;
		case PlayerScript::eWeapon::Bow:
			break;
		}
	}

	void PlayerScript::Attack2() {
		if (mState == PlayerScript::eState::Attack2) {
			switch (mWeapon) {
			case PlayerScript::eWeapon::ShortSword:
				Shield();
				break;
			case PlayerScript::eWeapon::Gloves:
				Glove();
				break;
			case PlayerScript::eWeapon::BigSword:
				BigSwordSpin();
				break;
			case PlayerScript::eWeapon::Spear:
				Spear();
				break;
			case PlayerScript::eWeapon::Bow:
				break;
			}
		}
		else if (mState == PlayerScript::eState::Attack2Shot) {
			switch (mWeapon) {
			case PlayerScript::eWeapon::ShortSword:
				CheckShieldMove();
				ShieldWalk();
				break;
			case PlayerScript::eWeapon::Gloves:
				GloveShot();
				break;
			case PlayerScript::eWeapon::BigSword:
				break;
			case PlayerScript::eWeapon::Spear:
				SpearShot();
				break;
			case PlayerScript::eWeapon::Bow:
				break;
			}
		}
	}

	void PlayerScript::Roll() {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (mAnimator->IsComplete()) {
			AnimationIdle();
		}
		else {
			switch (mDirection) {
			case PlayerScript::eDirection::Left:
				pos.x -= 600.0f * Time::DeltaTime();
				break;
			case PlayerScript::eDirection::Right:
				pos.x += 600.0f * Time::DeltaTime();
				break;
			case PlayerScript::eDirection::Up:
				pos.y -= 600.0f * Time::DeltaTime();
				break;
			case PlayerScript::eDirection::Down:
				pos.y += 600.0f * Time::DeltaTime();
				break;
			}
		}

		tr->SetPosition(pos);
	}

	void PlayerScript::ShortSword() //Attack Call
	{ 
		if (mAnimator->IsComplete())
			AnimationIdle();
	}

	void PlayerScript::Shield() {
		if (mAnimator->IsComplete()) {
			if(!Input::GetKey(eKeyCode::K)){
				AnimationShieldOff();
				AnimationIdle();
			}
			else {
				mState = PlayerScript::eState::Attack2Shot;
				AnimationAttack2Shot();
			}
		}
	}

	void PlayerScript::ShieldWalk() {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::D))
		{
			mb_Shield = true;
			mDirection = PlayerScript::eDirection::Right;
			pos.x += 200.0f * Time::DeltaTime();

		}
		if (Input::GetKey(eKeyCode::A))
		{
			mb_Shield = true;
			mDirection = PlayerScript::eDirection::Left;
			pos.x -= 200.0f * Time::DeltaTime();

		}
		if (Input::GetKey(eKeyCode::W))
		{
			mb_Shield = true;
			mDirection = PlayerScript::eDirection::Up;
			pos.y -= 200.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mb_Shield = true;
			mDirection = PlayerScript::eDirection::Down;
			pos.y += 200.0f * Time::DeltaTime();
		}
		if (!Input::GetKey(eKeyCode::K)) {
			AnimationIdle();
		}

		if (!(Input::GetKey(eKeyCode::D)||Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::S))) {
			mb_Shield = false;
		}

		tr->SetPosition(pos);
	}

	void PlayerScript::Glove() {
		if (mAnimator->IsComplete()) {
			if (mState == PlayerScript::eState::Attack1)
				AnimationIdle();
			if (mState == PlayerScript::eState::Attack2) {
				mState = PlayerScript::eState::Attack2Shot;
				AnimationAttack2Shot();
			}
		}
	}

	void PlayerScript::GloveShot() {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (mAnimator->IsComplete()) {
			AnimationIdle();
		}
		else {
			switch (mDirection) {
			case PlayerScript::eDirection::Left:
				pos.x -= 1000.0f * Time::DeltaTime();
				break;
			case PlayerScript::eDirection::Right:
				pos.x += 1000.0f * Time::DeltaTime();
				break;
			case PlayerScript::eDirection::Up:
				pos.y -= 1000.0f * Time::DeltaTime();
				break;
			case PlayerScript::eDirection::Down:
				pos.y += 1000.0f * Time::DeltaTime();
				break;
			}
		}

		tr->SetPosition(pos);
	}

	void PlayerScript::BigSword() {
		if (mAnimator->IsComplete()) {
				AnimationIdle();
		}
	}

	void PlayerScript::BigSwordSpin() {
		if (mAnimator->IsComplete()) {
			AnimationIdle();
		}
	}

	void PlayerScript::Spear() {
		if (mAnimator->IsComplete()) {
			if (mState == PlayerScript::eState::Attack1)
				AnimationIdle();
			if (mState == PlayerScript::eState::Attack2) {
				mState = PlayerScript::eState::Attack2Shot;
				AnimationAttack2Shot();
			}
		}
	}

	void PlayerScript::SpearShot() {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (mAnimator->IsComplete()) {
			AnimationSpearShot2();
		}
		else {
			switch (mDirection) {
			case PlayerScript::eDirection::Left:
				pos.x -= 400.0f * Time::DeltaTime();
				break;
			case PlayerScript::eDirection::Right:
				pos.x += 400.0f * Time::DeltaTime();
				break;
			case PlayerScript::eDirection::Up:
				pos.y -= 400.0f * Time::DeltaTime();
				break;
			case PlayerScript::eDirection::Down:
				pos.y += 400.0f * Time::DeltaTime();
				break;
			}
		}

		tr->SetPosition(pos);
	}

	void PlayerScript::SpearShot2() {
		if (mAnimator->IsComplete()) {
			AnimationIdle();
		}
	}

	void PlayerScript::Death() {
		mState = PlayerScript::eState::Death;
		if (mAnimator->IsComplete()) {
			AnimationIdle();
		}
		

	}

	void PlayerScript::UsePendant() {
		mState = PlayerScript::eState::Pendant;
		if (mAnimator->IsComplete()) {
			AnimationIdle();
		}
	}

	void PlayerScript::AnimationIdle() {
		mDirection = mFocusDirection;
		switch (mDirection) {
		case PlayerScript::eDirection::Left:
			mState = PlayerScript::eState::Idle;
			mDirection = PlayerScript::eDirection::Left;
			mAnimator->PlayAnimation(L"IdleLeft", true);

			break;
		case PlayerScript::eDirection::Right:
			mState = PlayerScript::eState::Idle;
			mDirection = PlayerScript::eDirection::Right;
			mAnimator->PlayAnimation(L"IdleRight", true);

			break;
		case PlayerScript::eDirection::Up:
			mState = PlayerScript::eState::Idle;
			mDirection = PlayerScript::eDirection::Up;
			mAnimator->PlayAnimation(L"IdleUp", true);

			break;
		case PlayerScript::eDirection::Down:
			mState = PlayerScript::eState::Idle;
			mDirection = PlayerScript::eDirection::Down;
			mAnimator->PlayAnimation(L"IdleDown", true);

			break;
		}
	}

	void PlayerScript::AnimationWalk() {
		switch (mDirection) {
		case PlayerScript::eDirection::Left:
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"WalkLeft");
			break;
		case PlayerScript::eDirection::Right:
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"WalkRight");
			break;
		case PlayerScript::eDirection::Up:
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"WalkUp");
			break;
		case PlayerScript::eDirection::Down:
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"WalkDown");
			break;
		}
	}

	void PlayerScript::AnimationRoll() {
		mState = PlayerScript::eState::Roll;
		switch (mDirection) {
		case SF::PlayerScript::eDirection::Left:
			mAnimator->PlayAnimation(L"RollLeft", false);
			break;
		case SF::PlayerScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RollRight", false);
			break;
		case SF::PlayerScript::eDirection::Up:
			mAnimator->PlayAnimation(L"RollUp", false);
			break;
		case SF::PlayerScript::eDirection::Down:
			mAnimator->PlayAnimation(L"RollDown", false);
			break;
		}
	}

	void PlayerScript::AnimationShieldOff() {
		switch (mFocusDirection) {
		case SF::PlayerScript::eDirection::Left:
			mAnimator->PlayAnimation(L"ShieldOffLeft", false);
			break;
		case SF::PlayerScript::eDirection::Right:
			mAnimator->PlayAnimation(L"ShieldOffRight", false);
			break;
		case SF::PlayerScript::eDirection::Up:
			mAnimator->PlayAnimation(L"ShieldOffUp", false);
			break;
		case SF::PlayerScript::eDirection::Down:
			mAnimator->PlayAnimation(L"ShieldOffDown", false);
			break;
		}
	}

	void PlayerScript::AnimationDeath() {
		mState = PlayerScript::eState::Death;
		mAnimator->PlayAnimation(L"Death", false);
	}

	void PlayerScript::AnimationPandent() {
		mState = PlayerScript::eState::Pendant;
		mAnimator->PlayAnimation(L"Pendant", false);
	}

	void PlayerScript::AnimationAttack1() {
		mState = PlayerScript::eState::Attack1;

		switch (mWeapon) {
		case SF::PlayerScript::eWeapon::ShortSword:
			switch (mDirection) {
			case SF::PlayerScript::eDirection::Left:
				mAnimator->PlayAnimation(L"sSwordAttackLeft", false);
				break;
			case SF::PlayerScript::eDirection::Right:
				mAnimator->PlayAnimation(L"sSwordAttackRight", false);
				break;
			case SF::PlayerScript::eDirection::Up:
				mAnimator->PlayAnimation(L"sSwordAttackUp", false);
				break;
			case SF::PlayerScript::eDirection::Down:
				mAnimator->PlayAnimation(L"sSwordAttackDown", false);
				break;
			}
			break;
		case SF::PlayerScript::eWeapon::Gloves:
			switch (mDirection) {
			case PlayerScript::eDirection::Left:
				mDirection = PlayerScript::eDirection::Left;
				mAnimator->PlayAnimation(L"GloveAttackLeft", false);
				break;
			case PlayerScript::eDirection::Right:
				mDirection = PlayerScript::eDirection::Right;
				mAnimator->PlayAnimation(L"GloveAttackRight", false);
				break;
			case PlayerScript::eDirection::Up:
				mDirection = PlayerScript::eDirection::Up;
				mAnimator->PlayAnimation(L"GloveAttackUp", false);
				break;
			case PlayerScript::eDirection::Down:
				mDirection = PlayerScript::eDirection::Down;
				mAnimator->PlayAnimation(L"GloveAttackDown", false);
				break;
			}
			break;

		case SF::PlayerScript::eWeapon::BigSword:
			switch (mDirection) {
			case PlayerScript::eDirection::Left:
				mDirection = PlayerScript::eDirection::Left;
				mAnimator->PlayAnimation(L"BigSwordAttackLeft", false);
				break;
			case PlayerScript::eDirection::Right:
				mDirection = PlayerScript::eDirection::Right;
				mAnimator->PlayAnimation(L"BigSwordAttackRight", false);
				break;
			case PlayerScript::eDirection::Up:
				mDirection = PlayerScript::eDirection::Up;
				mAnimator->PlayAnimation(L"BigSwordAttackUp", false);
				break;
			case PlayerScript::eDirection::Down:
				mDirection = PlayerScript::eDirection::Down;
				mAnimator->PlayAnimation(L"BigSwordAttackDown", false);
				break;
			}
			break;
		case SF::PlayerScript::eWeapon::Spear:
			switch (mDirection) {
			case PlayerScript::eDirection::Left:
				mDirection = PlayerScript::eDirection::Left;
				mAnimator->PlayAnimation(L"SpearAttackLeft", false);
				break;
			case PlayerScript::eDirection::Right:
				mDirection = PlayerScript::eDirection::Right;
				mAnimator->PlayAnimation(L"SpearAttackRight", false);
				break;
			case PlayerScript::eDirection::Up:
				mDirection = PlayerScript::eDirection::Up;
				mAnimator->PlayAnimation(L"SpearAttackUp", false);
				break;
			case PlayerScript::eDirection::Down:
				mDirection = PlayerScript::eDirection::Down;
				mAnimator->PlayAnimation(L"SpearAttackDown", false);
				break;
			}
			break;
		case SF::PlayerScript::eWeapon::Bow:
			break;
		}
	}

	void PlayerScript::AnimationAttack2() {
		mState = PlayerScript::eState::Attack2;
		switch (mWeapon) {
		case SF::PlayerScript::eWeapon::ShortSword: // 한손검 & 방패
			switch (mFocusDirection) {
			case SF::PlayerScript::eDirection::Left:
				mAnimator->PlayAnimation(L"ShieldLeft", false);
				break;
			case SF::PlayerScript::eDirection::Right:
				mAnimator->PlayAnimation(L"ShieldRight", false);
				break;
			case SF::PlayerScript::eDirection::Up:
				mAnimator->PlayAnimation(L"ShieldUp", false);
				break;
			case SF::PlayerScript::eDirection::Down:
				mAnimator->PlayAnimation(L"ShieldDown", false);
				break;
			}
			break;
		case SF::PlayerScript::eWeapon::Gloves: // 글러브
			switch (mDirection) {
			case PlayerScript::eDirection::Left:
				mDirection = PlayerScript::eDirection::Left;
				mAnimator->PlayAnimation(L"GloveAttack2Left", false);
				break;
			case PlayerScript::eDirection::Right:
				mDirection = PlayerScript::eDirection::Right;
				mAnimator->PlayAnimation(L"GloveAttack2Right", false);
				break;
			case PlayerScript::eDirection::Up:
				mDirection = PlayerScript::eDirection::Up;
				mAnimator->PlayAnimation(L"GloveAttack2Up", false);
				break;
			case PlayerScript::eDirection::Down:
				mDirection = PlayerScript::eDirection::Down;
				mAnimator->PlayAnimation(L"GloveAttack2Down", false);
				break;
			}
			break;
		case SF::PlayerScript::eWeapon::BigSword: //대검
			mDirection = PlayerScript::eDirection::Down;
			mAnimator->PlayAnimation(L"BigSwordSpin", false);
			break;
		case SF::PlayerScript::eWeapon::Spear:
			switch (mDirection) {
			case PlayerScript::eDirection::Left:
				mDirection = PlayerScript::eDirection::Left;
				mAnimator->PlayAnimation(L"SpearAttack2Left", false);
				break;
			case PlayerScript::eDirection::Right:
				mDirection = PlayerScript::eDirection::Right;
				mAnimator->PlayAnimation(L"SpearAttack2Right", false);
				break;
			case PlayerScript::eDirection::Up:
				mDirection = PlayerScript::eDirection::Up;
				mAnimator->PlayAnimation(L"SpearAttack2Up", false);
				break;
			case PlayerScript::eDirection::Down:
				mDirection = PlayerScript::eDirection::Down;
				mAnimator->PlayAnimation(L"SpearAttack2Down", false);
				break;
			}
			break;
		case SF::PlayerScript::eWeapon::Bow:
			break;
		}
	}

	void PlayerScript::AnimationAttack2Shot() {
		mState = PlayerScript::eState::Attack2Shot;
		switch (mWeapon) {
		case PlayerScript::eWeapon::ShortSword:
			if (!Input::GetKey(eKeyCode::K)) {
				AnimationIdle();
			} 
			else if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::A) ||
				Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::S)){
				mb_Shield = true;
				CheckShieldMove();
			}
			break;
		case PlayerScript::eWeapon::Gloves:
			switch (mDirection) {
			case PlayerScript::eDirection::Left:
				mAnimator->PlayAnimation(L"GloveAttack2ShotLeft", false);
				break;
			case PlayerScript::eDirection::Right:
				mAnimator->PlayAnimation(L"GloveAttack2ShotRight", false);
				break;
			case PlayerScript::eDirection::Up:
				mAnimator->PlayAnimation(L"GloveAttack2ShotUp", false);
				break;
			case PlayerScript::eDirection::Down:
				mAnimator->PlayAnimation(L"GloveAttack2ShotDown", false);
				break;
			}
			break;
		case PlayerScript::eWeapon::BigSword:
			break;
		case PlayerScript::eWeapon::Spear:
			switch (mDirection) {
			case PlayerScript::eDirection::Left:
				mAnimator->PlayAnimation(L"SpearAttack2ShotLeft", false);
				break;
			case PlayerScript::eDirection::Right:
				mAnimator->PlayAnimation(L"SpearAttack2ShotRight", false);
				break;
			case PlayerScript::eDirection::Up:
				mAnimator->PlayAnimation(L"SpearAttack2ShotUp", false);
				break;
			case PlayerScript::eDirection::Down:
				mAnimator->PlayAnimation(L"SpearAttack2ShotDown", false);
				break;
			}
			break;
		}
	}

	void PlayerScript::AnimationSpearShot2() {
		mState = PlayerScript::eState::Attack2Shot2;
		switch (mDirection) {
		case PlayerScript::eDirection::Left:
			mAnimator->PlayAnimation(L"SpearAttack2Shot2Left", false);
			break;
		case PlayerScript::eDirection::Right:
			mAnimator->PlayAnimation(L"SpearAttack2Shot2Right", false);
			break;
		case PlayerScript::eDirection::Up:
			mAnimator->PlayAnimation(L"SpearAttack2Shot2Up", false);
			break;
		case PlayerScript::eDirection::Down:
			mAnimator->PlayAnimation(L"SpearAttack2Shot2Down", false);
			break;
		}
	}

	void PlayerScript::CheckShieldMove() {

		if (mAnimator->IsComplete() && (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::D))) {
			switch (mFocusDirection) {
			case PlayerScript::eDirection::Left:
				mAnimator->PlayAnimation(L"ShieldWalkLeft");
				break;
			case PlayerScript::eDirection::Right:
				mAnimator->PlayAnimation(L"ShieldWalkRight");
				break;
			case PlayerScript::eDirection::Up:
				mAnimator->PlayAnimation(L"ShieldWalkUp");
				break;
			case PlayerScript::eDirection::Down:
				mAnimator->PlayAnimation(L"ShieldWalkDown");
				break;
			}
		}
		else if (mb_Shield == false){
			switch (mFocusDirection) {
			case PlayerScript::eDirection::Left:
				mAnimator->PlayAnimation(L"ShieldOffLeft", false);
				break;
			case PlayerScript::eDirection::Right:
				mAnimator->PlayAnimation(L"ShieldOffRight", false);
				break;
			case PlayerScript::eDirection::Up:
				mAnimator->PlayAnimation(L"ShieldOffUp", false);
				break;
			case PlayerScript::eDirection::Down:
				mAnimator->PlayAnimation(L"ShieldOffDown", false);
				break;
			}
		}
	}


}
