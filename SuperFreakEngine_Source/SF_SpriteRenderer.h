#pragma once
#include "SF_Entity.h"
#include "SF_Component.h"
#include "SF_Texture.h"

namespace SF {
	class SpriteRenderer : public Component {
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(Graphics::Texture* texture) {
			mTexture = texture;
		}
		void SetSize(math::Vector2 size) {
			mSize = size;
		}
	private:
		Graphics::Texture* mTexture;
		math::Vector2 mSize;
	};
}

