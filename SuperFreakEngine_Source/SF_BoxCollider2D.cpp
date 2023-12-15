#include "SF_BoxCollider2D.h"
#include "SF_Transform.h"
#include "SF_GameObject.h"
#include "SF_Renderer.h"
#include "SF_Camera.h"

namespace SF {
	BoxCollider2D::BoxCollider2D()
	: Collider(enums::eColliderType::Rect2D) 
	{}
	
	BoxCollider2D::~BoxCollider2D() {}

	void BoxCollider2D::Initialize() {}

	void BoxCollider2D::Update() {}

	void BoxCollider2D::LateUpdate() {}

	void BoxCollider2D::Render(HDC hdc) {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Renderer::mainCamera)
			pos = Renderer::mainCamera->CaluatePosition(pos);

		Vector2 offset = GetOffset();

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

		Rectangle(hdc, pos.x + offset.x
			, pos.y + offset.y
			, pos.x + offset.x + 64 * GetSize().x
			, pos.y + offset.y + 64 * GetSize().y);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);
		DeleteObject(greenPen);
	}
}