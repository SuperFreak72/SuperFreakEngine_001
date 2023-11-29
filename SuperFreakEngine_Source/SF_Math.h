#pragma once

namespace SF::math {
	struct Vector2 {
		static Vector2 One;
		static Vector2 Zero;

		float x;
		float y;
		
		Vector2() : x(0.0f), y(0.0f) {}

		Vector2(float x, float y) {
			this->x = x;
			this->y = y;
		}

		Vector2 operator+ (Vector2 value) {
			return Vector2(x + value.x, y + value.y);
		}

		Vector2 operator- (Vector2 value) {
			return Vector2(x - value.x, y - value.y);
		}

		Vector2 operator/(float value) {
			return Vector2(x / value, y / value);
		}
	};
}

