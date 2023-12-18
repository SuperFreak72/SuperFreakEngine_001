#include "SF_BackGround.h"
#include "SF_Input.h"
#include "SF_Transform.h"
#include "SF_Time.h"


namespace SF {
	void BackGround::Initialize() {
		GameObject::Initialize();
	}
	void BackGround::Update() {
		GameObject::Update();
	}
	void BackGround::LateUpdate() {
		GameObject::LateUpdate();
	}
	void BackGround::Render(HDC hdc) {
		GameObject::Render(hdc);
	}
}
