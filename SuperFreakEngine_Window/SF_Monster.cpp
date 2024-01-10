#include "SF_Monster.h"
#include "SF_Camera.h"
#include "SF_Renderer.h"
#include "SF_Input.h"
#include "SF_Transform.h"
#include "SF_Time.h"
#include "SF_BoxCollider2D.h"

namespace SF {
	void Monster::Initialize() {
		GameObject::Initialize();
	}	 
	
	void Monster::Update() {
		GameObject::Update();
	}
	
	void Monster::LateUpdate() {
		GameObject::LateUpdate();
	}	 
		 
	void Monster::Render(HDC hdc) {
		Transform* trMonster = this->GetComponent<Transform>();
		Vector2 monPos = trMonster->GetPosition();
		Vector2 pos = Renderer::mainCamera->CaluatePosition(monPos);
		HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

		Rectangle(hdc, pos.x
			, pos.y
			, pos.x + 128
			, pos.y + 128);

		SelectObject(hdc, oldBrush);
		DeleteObject(myBrush);

		trMonster->SetPosition(monPos);
		GameObject::Render(hdc);
	}	 
}
