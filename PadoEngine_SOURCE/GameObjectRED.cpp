#include "pGameObjectRED.h"

namespace p
{
	GameObjectRED::GameObjectRED()
	{
		mX = 0.0f;
		mY = 0.0f;
	}
	GameObjectRED::~GameObjectRED()
	{

	}

	void GameObjectRED::Update()
	{
		if (GetAsyncKeyState('A') & 0x8000)
		{
			mX -= 0.01f;
		}
		if (GetAsyncKeyState('D') & 0x8000)
		{
			mX += 0.01f;
		}
		if (GetAsyncKeyState('W') & 0x8000)
		{
			mY -= 0.01f;
		}
		if (GetAsyncKeyState('S') & 0x8000)
		{
			mY += 0.01f;
		}
	}

	void GameObjectRED::LateUpdate()
	{

	}

	void GameObjectRED::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Ellipse(hdc, 1200 + mX, 700 + mY, 1300 + mX, 800 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
		DeleteObject(redPen);

	}

}