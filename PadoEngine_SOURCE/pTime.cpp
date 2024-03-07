#include "pTime.h"

namespace p
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;

	void Time::Initialize()
	{
		// CPU ���� ������
		QueryPerformanceFrequency(&CpuFrequency);

		// ���α׷� ���� ���� ���� ���� Ƚ��
		QueryPerformanceCounter(&PrevFrequency);
	}
	void Time::Update()
	{
		// ���α׷� �� ����Ŭ ���� ���� ���� Ƚ��
		QueryPerformanceCounter(&CurrentFrequency);

		float differeceFrequency
			= static_cast<float> (CurrentFrequency.QuadPart - PrevFrequency.QuadPart);
		DeltaTimeValue = differeceFrequency / static_cast<float> (CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"FPS : %d", (int)fps);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
}