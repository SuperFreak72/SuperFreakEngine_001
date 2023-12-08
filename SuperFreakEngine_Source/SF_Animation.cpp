#include "SF_Animation.h"
#include "SF_Time.h"
#include "SF_Transform.h"
#include "SF_GameObject.h"
#include "SF_Animator.h"
#include "SF_Renderer.h"
#include "SF_Camera.h"

namespace SF {
	Animation::Animation()
		: Resource(enums::eResourceType::Animation)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		, mIndex(-1)
		, mTime(0.0f)
		, mb_Complete(false)
	{}
	Animation::~Animation() {}

	HRESULT Animation::Load(const std::wstring& path) {
		return E_NOTIMPL;
	}

	void Animation::Update() {
		if (mb_Complete)
			return;
		mTime += Time::DeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime) {
			mTime = 0.0f;
			if (mIndex < mAnimationSheet.size() - 1)
				mIndex++;
			else
				mb_Complete = true;
		}
	}

	void Animation::Render(HDC hdc) {
		if (mTexture == nullptr)
			return;

		GameObject* gameObj = mAnimator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRoation();
		Vector2 scale = tr->GetScale();

		if (Renderer::mainCamera)
			pos = Renderer::mainCamera->CaluatePosition(pos);

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

		Sprite sprite = mAnimationSheet[mIndex];
		HDC imgHdc = mTexture->GetHdc();

		AlphaBlend(hdc
			, pos.x + sprite.offset.x , pos.y + sprite.offset.y
			, sprite.size.x * scale.x
			, sprite.size.y * scale.y
			, imgHdc
			, sprite.leftTop.x
			, sprite.leftTop.y
			, sprite.size.x
			, sprite.size.y
			, func);
	}
	void Animation::CreateAnimation(const std::wstring& name, Graphics::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration) {
		mTexture = spriteSheet;
		if (spriteSheet->GetWidth() < spriteLength * size.x) {
			UINT frame = spriteSheet->GetWidth() / size.x;
			for (size_t j = 0; j < spriteLength / frame; j++) {
				for (size_t i = 0; i < frame; i++)
				{
					Sprite sprite = {};
					sprite.leftTop.x = leftTop.x + (size.x * i);
					sprite.leftTop.y = leftTop.y + (size.y * j);
					sprite.size = size;
					sprite.offset = offset;
					sprite.duration = duration;

					mAnimationSheet.push_back(sprite);
				}
			}
		}
		else {
			for (size_t i = 0; i < spriteLength; i++)
			{

				Sprite sprite = {};
				sprite.leftTop.x = leftTop.x + (size.x * i);
				sprite.leftTop.y = leftTop.y;
				sprite.size = size;
				sprite.offset = offset;
				sprite.duration = duration;

				mAnimationSheet.push_back(sprite);
			}
		}
	}
	void Animation::Reset() {
		mTime = 0.0f;
		mIndex = 0;
		mb_Complete = false;
	}
}