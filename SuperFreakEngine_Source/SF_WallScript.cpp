#include "SF_WallScript.h"
#include "SF_GameObject.h"
#include "SF_Object.h"
#include "SF_Resources.h"

namespace SF {
	WallScript::WallScript() {}
	WallScript::~WallScript() {}

	void WallScript::Initialize() {}
	void WallScript::Update() {}
	void WallScript::LateUpdate() {}
	void WallScript::Render(HDC hdc) {}

	void WallScript::OnCollisionEnter(Collider* other) {
		
	}
	void WallScript::OnCollisionStay(Collider* other) {
		Transform* objTr = other->GetOwner()->GetComponent<Transform>();
		Collider* objCol = other;

		Transform* wallTr = this->GetOwner()->GetComponent<Transform>();
		Collider* wallCol = this->GetOwner()->GetComponent<Collider>();

		if (objTr->GetPosition().x > wallTr->GetPosition().x) {
			Vector2 objPos = objTr->GetPosition();
			objPos.x += 5.0f;
			objTr->SetPosition(objPos);
		}
		else if (objTr->GetPosition().x < wallTr->GetPosition().x) {
			Vector2 objPos = objTr->GetPosition();
			objPos.x -= 5.0f;
			objTr->SetPosition(objPos);
		}

		if (objTr->GetPosition().y > wallTr->GetPosition().y) {
			Vector2 objPos = objTr->GetPosition();
			objPos.y += 5.0f;
			objTr->SetPosition(objPos);
		}
		else if (objTr->GetPosition().y < wallTr->GetPosition().y) {
			Vector2 objPos = objTr->GetPosition();
			objPos.y -= 5.0f;
			objTr->SetPosition(objPos);
		}
	}
	void WallScript::OnCollisionExit(Collider* other)
	{
	}
}