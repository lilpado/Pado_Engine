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
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void UpdateRED();
		void LateUpdateRED();
		void RenderRED(HDC hdc);

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
		// 게임 오브젝트의 좌표
		float mX;
		float mY;
		std::vector<Bullet> mBullets;
	};
}