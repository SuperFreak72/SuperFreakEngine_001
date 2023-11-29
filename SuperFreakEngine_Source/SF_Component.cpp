#include "SF_Component.h"

namespace SF {
	Component::Component(enums::eComponentType type)
	: mType(type)
	{}
	Component::~Component() {
	}
	void SF::Component::Initialize() {
	}
	void SF::Component::Update() {
	}
	void SF::Component::LateUpdate() {
	}
	void SF::Component::Render(HDC hdc) {
	}
}