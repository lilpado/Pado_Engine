#pragma once
#include "pGameObject.h"
#include "pRanObject.h"
#include "pTime.h"

namespace p
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		
		void Update();
		void LateUpdate();
		void Render();


	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;
		
		// 플레이어 (조작)
		GameObject mPlayer;
		GameObject mPlayerRED;
		RanObject mObstacle;
	};
}

