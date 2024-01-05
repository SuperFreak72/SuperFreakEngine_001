#include "SF_Camera.h"
#include "SF_GameObject.h"
#include "SF_Transform.h"
#include "SF_Application.h"

extern SF::Application app;

namespace SF {
	Camera::Camera()
	: Component(enums::eComponentType::Camera)
	, mDistance(Vector2::Zero)
	, mResolution(Vector2::Zero)
	, mLookPosition(Vector2::Zero)
	, mTarget(nullptr)
	{}

	Camera::~Camera() {}

	void Camera::Initialize() {
		mResolution.x = app.GetWidth();
		mResolution.y = app.GetHeight();
	}

	void Camera::Update() {
		if (mTarget) {
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}
		else
		{
			Transform* cameraTr = GetOwner()->GetComponent<Transform>();
			mLookPosition = cameraTr->GetPosition();
		}
		mDistance = mLookPosition - (mResolution / 2.0f);
	}

	void Camera::LateUpdate() { }

	void Camera::Render(HDC hdc) { }
}
