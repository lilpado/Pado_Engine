#pragma once
#include "pGameObject.h"
#include "pRanObject.h"

namespace p
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();
		
		void Update();
		void LateUpdate();
		void Render();


	private:
		HWND mHwnd;
		HDC mHdc;
		
		// 플레이어 (조작)
		GameObject mPlayer;
		GameObject mPlayerRED;
		RanObject mObstacle;
	};
}

