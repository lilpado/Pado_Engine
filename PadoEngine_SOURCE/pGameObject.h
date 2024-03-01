#pragma once
#include "CommonInclude.h"

namespace p
{
	// Actor
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void UpdateRED();
		void LateUpdateRED();
		void RenderRED(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX() { return mX;}
		float GetPositionY() { return mY;}

	private:
		// ���� ������Ʈ�� ��ǥ
		float mX;
		float mY;
	};
}