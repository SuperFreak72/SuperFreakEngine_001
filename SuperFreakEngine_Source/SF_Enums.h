#pragma once


namespace SF::enums {
	enum class eComponentType {
		Transform,
		Collider,
		Script,
		SpriteRenderer,
		Animator,
		Camera,
		End,
	};

	enum class eLayerType {
		None,
		BackGround,
		BackObject,
		BackUI,
		Player,
		Monster,
		UnderUI,
		Particle,
		UI,
		Max = 16,
	};

	enum class eResourceType {
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};

	enum class eColliderType {
		Circle2D,
		Rect2D,
		End,
	};
}