#pragma once
#include "CommonInclude.h"
#include "SF_Math.h"
using namespace SF::math;

namespace SF {
	class Entity {
	public:
		Entity();
		virtual ~Entity();
		void SetName(const std::wstring& name) {
			mName = name;
		}
		std::wstring& GetName() {
			return mName;
		}
	private:
		std::wstring mName;
	};
}

