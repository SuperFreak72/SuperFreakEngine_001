#pragma once
#include "SF_Entity.h"

namespace SF {
	 class Resource abstract : public Entity {
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // 0을 쓰면 순수가상함수 실제메모리 할당 불가

		const std::wstring& GetPath() {
			return mPath;
		}

		void SetPath(const std::wstring& path) {
			mPath = path;
		}

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
		
	};

	class AudioClip : public Resource {

	};
}

