#include "SF_EnterScript.h"
#include "SF_Input.h"
#include "SF_Time.h"
#include "SF_GameObject.h"
#include "SF_Animator.h"
#include "SF_Object.h"
#include "SF_Resources.h"
#include "SF_SceneManager.h"

namespace SF {
	EnterScript::EnterScript() {}
	EnterScript::~EnterScript() {}

	void EnterScript::Initialize()
	{
	}

	void EnterScript::Update()
	{
	}

	void EnterScript::LateUpdate()
	{
	}

	void EnterScript::Render(HDC hdc)
	{
	}

	void EnterScript::OnCollisionEnter(Collider* other) {
		
	}

	void EnterScript::OnCollisionStay(Collider* other) {
		if (Input::GetKeyDown(eKeyCode::H)) {
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void EnterScript::OnCollisionExit(Collider* other)
	{
	}
}
