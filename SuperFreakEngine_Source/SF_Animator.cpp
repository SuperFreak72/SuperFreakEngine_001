#include "SF_Animator.h"

namespace SF {
	Animator::Animator()
	: Component(enums::eComponentType::Animator)
	, mAnimations{}
	, mActiveAnimation(nullptr)
	, mb_Loop(false)
	{}
	Animator::~Animator() {}

	void Animator::Initialize() {}

	void Animator::Update() {
		if (mActiveAnimation) {
			mActiveAnimation->Update();
			if (mActiveAnimation->IsComplete() == true && mb_Loop == true) {
				mActiveAnimation->Reset();
			}
		}
	}

	void Animator::LateUpdate() {}
	void Animator::Render(HDC hdc) {
		if (mActiveAnimation)
			mActiveAnimation->Render(hdc);
	}
	void Animator::CreateAnimation(const std::wstring& name, Graphics::Texture* spriteSheet, 
		Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration) {
		Animation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation != nullptr)
			return;

			animation = new Animation();
			animation->CreateAnimation(name, spriteSheet
				, leftTop, size, offset, spriteLength, duration);

			animation->SetAnimator(this);

		mAnimations.insert(std::make_pair(name, animation));
	}

	Animation* Animator::FindAnimation(const std::wstring& name) {
		auto iter = mAnimations.find(name);
		if (iter == mAnimations.end())
			return nullptr;

		return iter->second;
	}
	void Animator::PlayAnimation(const std::wstring& name, bool loop) {
		Animation* animation = FindAnimation(name);
		if (animation == nullptr)
			return;

		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mb_Loop = loop;
	}

	Animator::Events* Animator::FindEvents(const std::wstring& name)
	{
		auto iter = mEvents.find(name);
		if (iter == mEvents.end())
			return nullptr;

		return iter->second;
	}
	std::function<void()>& Animator::GetStartEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->startEvent.mEvent;
	}
	std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->completeEvent.mEvent;
	}
	std::function<void()>& Animator::GetEndEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->endEvent.mEvent;
	}
}