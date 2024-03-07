#include "pGameObject.h"
#include "pInput.h"
#include "pTime.h"

namespace p
{
	GameObject::GameObject()
	{
		mX = 0.0f;
		mY = 0.0f;
	}
	GameObject::~GameObject()
	{

	}

	void GameObject::Update() 
	{
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mX += speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::W))
		{
			mY -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mY += speed * Time::DeltaTime();
		}
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		// 파랑 브러쉬 생성
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));

		// 파랑 브러쉬 DC에 선택 & 흰색(default) 브러쉬 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
		DeleteObject(redPen);

	}

	void GameObject::UpdateRED()
	{
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::Left))
		{
			mX -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mX += speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			mY -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mY += speed * Time::DeltaTime();
		}
	}
	void GameObject::LateUpdateRED() 
	{

	}
	void GameObject::RenderRED(HDC hdc)
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