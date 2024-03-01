#pragma once
#include "CommonInclude.h"

namespace p
{
	class RanObject
	{
	public:
		RanObject();
		~RanObject();

		void Update(HWND hwnd);
		void LateUpdate();
		void Render(HDC hdc);


		void DrawCircle0();
		void DrawCircle1();
		void DrawCircle2();

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		void ChangeStep()
		{
			currStep = (currStep + 1) % 3;
		}

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

	private:
		float mX;
		float mY;
		float speed = 0.01f;
		float angle = 45.0f;
		int currStep = 0;
		int radius = 100;
	};
}