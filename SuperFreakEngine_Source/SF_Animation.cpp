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
		// 알파블렌드를 쓸수 있는 조건 : 해당이미지 알파채널이 있어야한다.
		//AlphaBlend(125, );


		if (mTexture == nullptr)
			return;

		GameObject* gameObj = mAnimator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRoation();
		Vector2 scale = tr->GetScale();

		if (Renderer::mainCamera)
			pos = Renderer::mainCamera->CaluatePosition(pos);

		Sprite sprite = mAnimationSheet[mIndex];
		Graphics::Texture::eTextureType type = mTexture->GetTextureType();
		if (type == Graphics::Texture::eTextureType::Bmp) {
			HDC imgHdc = mTexture->GetHdc();

			if (mTexture->IsAlpha()) {
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc
					, pos.x - (sprite.size.x / 2.0f) + sprite.offset.x
					, pos.y - (sprite.size.y / 2.0f) + sprite.offset.y
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc
					, sprite.leftTop.x
					, sprite.leftTop.y
					, sprite.size.x
					, sprite.size.y
					, func);
			}
			else {
				TransparentBlt(hdc
					, pos.x - (sprite.size.x / 2.0f) + sprite.offset.x
					, pos.y - (sprite.size.y / 2.0f) + sprite.offset.y
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc
					, sprite.leftTop.x
					, sprite.leftTop.y
					, sprite.size.x
					, sprite.size.y
					, RGB(255, 0, 255));
			}

			Rectangle(hdc, pos.x, pos.y, pos.x + 10, pos.y + 10);
		}
		else if (type == Graphics::Texture::eTextureType::Png) {
			// 내가 원하는 픽셀을 투명화 시킬
			Gdiplus::ImageAttributes imgAtt = {};

			// 투명화 시킬 픽셀의 색 범위
			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect (
					pos.x - (sprite.size.x / 2.0f)
					, pos.y - (sprite.size.y / 2.0f)
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
				)
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, Gdiplus::UnitPixel
				, /*&imgAtt*/nullptr
			);
		}

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