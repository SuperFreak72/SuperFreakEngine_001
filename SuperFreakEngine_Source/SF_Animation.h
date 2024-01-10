#pragma once
#include "SF_Resource.h"
#include "SF_Texture.h"


using namespace SF::math;
namespace SF {
	class Animation : public Resource{
	public:
		struct Sprite {
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
			: leftTop(Vector2::Zero)
			, size(Vector2::Zero)
			, offset(Vector2::Zero)
			,duration(0.0f)
			{}
		};
		Animation();
		~Animation();

		HRESULT Load(const std::wstring& path) override;

		void Update();
		void Render(HDC hdc);

		void CreateAnimation(const std::wstring& name
			, Graphics::Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLength
			, float duration);

		void Reset();

		bool IsComplete() {
			return mb_Complete;
		}
		void SetAnimator(class Animator* animator) {
			mAnimator = animator;
		};

		int GetIndex() { return mIndex; }

	private:
		class Animator* mAnimator;
		Graphics::Texture* mTexture;

		std::vector<Sprite> mAnimationSheet;
		int mIndex;
		float mTime;
		bool mb_Complete;
	};
}

