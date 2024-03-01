#include "pRanObject.h"
#define M_PI 3.141592

namespace p
{
	RanObject::RanObject()
	{
		mX = 0.0f;
		mY = 0.0f;
	}

	RanObject::~RanObject()
	{

	}

	void RanObject::Update(HWND hwnd)
	{
		if (GetAsyncKeyState(VK_LBUTTON) & 0x01)
		{
			ChangeStep();
			InvalidateRect(hwnd, NULL, true);
		}
		else
		{
			switch (currStep)
			{
			case 0:
				DrawCircle0();
				break;

			case 1:
				DrawCircle1();
				break;

			case 2:
				DrawCircle2();
				break;

			}
		}
	}

	void RanObject::LateUpdate()
	{

	}

	void RanObject::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		HPEN whitePen = (HPEN)GetStockObject(WHITE_PEN);
		HPEN oldPen = (HPEN)SelectObject(hdc, whitePen);

		Ellipse(hdc, 600 + mX, 400 + mY, 650 + mX, 450 + mY);

		SelectObject(hdc, oldPen);
		SelectObject(hdc, oldBrush);
		DeleteObject(brush);

	}

	void RanObject::DrawCircle0()
	{
		angle += (5 * speed);
		mX = radius * std::cos(angle * M_PI / 180);
		mY = radius * std::sin(angle * M_PI / 180);
	}
	void RanObject::DrawCircle1()
	{
		angle += (5 * speed);
		mX = radius / 2 * std::cos(3 * angle * M_PI / 180);
		mY = radius / 2 * std::sin(3 * angle * M_PI / 180);
	}
	void RanObject::DrawCircle2()
	{
		angle += (5 * speed);
		mX = radius / 3 * std::cos(10 * angle * M_PI / 180);
		mY = radius / 3 * std::sin(10 * angle * M_PI / 180);
	}
}