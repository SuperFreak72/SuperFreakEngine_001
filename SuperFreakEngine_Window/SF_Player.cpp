#include "SF_Player.h"

namespace SF {
	void Player::Initialize() {
		GameObject::Initialize();
	}
	void Player::Update() {
		GameObject::Update();
	}
	void Player::LateUpdate() {
		GameObject::LateUpdate();
	}
	void Player::Render(HDC hdc){
		GameObject::Render(hdc);
	}
}
