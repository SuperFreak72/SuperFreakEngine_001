#pragma once


namespace SF::enums {
	enum class eComponentType {
		Transform,
		Collider,
		Rigidbody,
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
		Monster,
		Player,
		UnderUI,
		Particle,
		UI,
		Max = 16,
		End,
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