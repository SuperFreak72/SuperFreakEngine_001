#pragma once
#include "SF_Entity.h"

namespace SF {
	 class Resource abstract : public Entity {
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // 0�� ���� ���������Լ� �����޸� �Ҵ� �Ұ�

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

