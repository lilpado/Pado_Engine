#include "pGameObject.h"
#include "pInput.h"
#include "pTime.h"

namespace p
{
	GameObject::GameObject()
	{
		mX = 0.0f;
		mY = 0.0f;
		mRGB = 0;
	}

	GameObject::GameObject(int RGB)
	{
		mX = 0.0f;
		mY = 0.0f;
		mRGB = RGB;
	}
	GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{
		if (mRGB == 0)
			UpdateRED();
		else if (mRGB == 2)
			UpdateBLUE();
		 
	}
	void GameObject::LateUpdate()
	{
		if (mRGB == 0)
			LateUpdateRED();
		else if (mRGB == 2)
			LateUpdateBLUE();

	}
	void GameObject::Render(HDC hdc)
	{
		if (mRGB == 0)
			RenderRED(hdc);
		else if (mRGB == 2)
			RenderBLUE(hdc);

	}

	void GameObject::UpdateRED()
	{
		const int speed = 150.0f;
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
		if (Input::GetKeyDown(eKeyCode::Space))
		{
			GenerateBullet();
		}

		UpdateBullet();
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

		Ellipse(hdc, mX, 700 + mY, 100 + mX, 800 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
		DeleteObject(redPen);

		RenderBullet(hdc);
	}

	void GameObject::UpdateBLUE()
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

	void GameObject::LateUpdateBLUE()
	{

	}

	void GameObject::RenderBLUE(HDC hdc)
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


	void GameObject::GenerateBullet()
	{
		Bullet bullet(50 + mX, 700 + mY, 200.0f);
		mBullets.push_back(bullet);
	}

	void GameObject::UpdateBullet()
	{
		for (int i = 0; i < mBullets.size(); i++)
		{
			mBullets[i].y -= mBullets[i].speed * Time::DeltaTime();
		}
	}

	void GameObject::RenderBullet(HDC hdc)
	{
		for (int i = 0; i < mBullets.size(); i++)
		{
			HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
			HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

			Ellipse(hdc, mBullets[i].x - 10, mBullets[i].y - 10
				, mBullets[i].x + 10, mBullets[i].y + 10);

			SelectObject(hdc, oldbrush);
			DeleteObject(brush);
		}
	}	
}