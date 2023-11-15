#include "SF_GameObject.h"
#include "SF_Input.h"
#include "SF_Time.h"
#include "SF_Bullet.h"

namespace SF {
	GameObject::GameObject(): mX(0), mY(0) { }
	GameObject::~GameObject() { }

	void GameObject::Update() {
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::A)) {
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D)) {
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::W)) {
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S)) {
			mY += speed * Time::DeltaTime();
		}
	}

	void GameObject::LateUpdate() { }

	void GameObject::Render(HDC hdc) {
		//파랑 브러쉬 생성
		HBRUSH blueBrush = CreateSolidBrush(RGB(0,0,0));

		// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(0,0,0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Ellipse(hdc, mX, mY, 100 + mX, 100 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}


