#include "pTime.h"

namespace p
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;

	void Time::Initialize()
	{
		// CPU 고유 진동수
		QueryPerformanceFrequency(&CpuFrequency);

		// 프로그램 시작 시점 누적 진동 횟수
		QueryPerformanceCounter(&PrevFrequency);
	}
	void Time::Update()
	{
		// 프로그램 한 사이클 이후 누적 진동 횟수
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