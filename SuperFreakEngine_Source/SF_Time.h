#pragma once
#include "CommonInclude.h"

namespace SF {
	class Time {
	public:
		static void Initailize();
		static void Update();
		static void Render(HDC hdc);

		__forceinline static float DeltaTime() { return deltaTime; }
	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float deltaTime;
	};
}

