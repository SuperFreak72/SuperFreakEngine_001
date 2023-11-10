#include "SFTime.h"

namespace SF {
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::deltaTime = 0.0f;

	void SF::Time::Initailize()
	{
		QueryPerformanceFrequency(&CpuFrequency); // CPU ���� ������
		QueryPerformanceCounter(&PrevFrequency); // ���α׷��� �������� �� ���� ���� ��
	}

	void SF::Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float diffarenceFrequeny = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);
		deltaTime = static_cast<float>(diffarenceFrequeny / CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += deltaTime;
		float fps = 1.0f / deltaTime;

		//char str2 = 'A'; ���ͷ�
		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)fps);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);


	}
}
