#pragma once
#include "SF_Component.h"
#include "SF_Animation.h"

using namespace SF::math;
namespace SF {
	class Animator : public Component{
	public:
		struct Event {
			void operator=(std::function<void()> func) {
				mEvent = std::move(func);
			}

			void operator()() {
				if (mEvent)
					mEvent();
			}
			std::function<void()> mEvent;
		};
		struct Events
		{
			Event startEvent;
			Event completeEvent;
			Event endEvent;
		};

		Animator();
		~Animator();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void CreateAnimation( const std::wstring& name 
			, Graphics::Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLength
			, float duration );

		Animation* FindAnimation(const std::wstring& name);

		void PlayAnimation(const std::wstring& name, bool loop = true);

		Events* FindEvents(const std::wstring& name);
		std::function<void()>& GetStartEvent(const std::wstring& name);
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		std::function<void()>& GetEndEvent(const std::wstring& name);

		bool IsComplete() { return mActiveAnimation->IsComplete(); }

	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mb_Loop;

		std::map<std::wstring, Events*> mEvents;
	};
}

