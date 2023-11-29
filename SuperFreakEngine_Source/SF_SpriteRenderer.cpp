#include "SF_SpriteRenderer.h"
#include "SF_GameObject.h"
#include "SF_Transform.h"
#include "SF_Texture.h"
#include "SF_Renderer.h"

namespace SF {
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(Vector2::One)
	{ }
	SpriteRenderer::~SpriteRenderer() { }

	void SpriteRenderer::Initialize() { }

	void SpriteRenderer::Update() { }

	void SpriteRenderer::LateUpdate() { }

	void SpriteRenderer::Render(HDC hdc) {
		if (mTexture == nullptr)
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos = Renderer::mainCamera->CaluatePosition(pos);

		if (mTexture->GetTextureType()
			== Graphics::Texture::eTextureType::Bmp)
		{
			//https://blog.naver.com/power2845/50147965306
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y
				, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == 
			Graphics::Texture::eTextureType::Png) {

			Gdiplus::Graphics graphcis(hdc);
			graphcis.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect(pos.x, pos.y
					, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
		}

	}
}

