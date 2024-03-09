#pragma once
#include "CommonInclude.h"

namespace p
{
	// Actor
	class GameObject
	{
	public:
		struct Bullet
		{
			float x;
			float y;
			float speed;
		};

		GameObject();
		GameObject(int RGB);
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void UpdateRED();
		void LateUpdateRED();
		void RenderRED(HDC hdc);

		void UpdateBLUE();
		void LateUpdateBLUE();
		void RenderBLUE(HDC hdc);

		void GenerateBullet();
		void UpdateBullet();
		void RenderBullet(HDC hdc);

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
		int mRGB;
		std::vector<Bullet> mBullets;
	};
}