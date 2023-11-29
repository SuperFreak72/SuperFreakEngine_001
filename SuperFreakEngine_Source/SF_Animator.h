#pragma once
#include "SF_Component.h"
#include "SF_Animation.h"

using namespace SF::math;
namespace SF {
	class Animator : public Component{
	public:
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
	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mb_Loop;
	};
}

