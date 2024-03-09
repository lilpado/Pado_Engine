#pragma once
#include "CommonInclude.h"
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
		void clearRenderTarget();
		void copyRenderTarget(HDC src, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;
		
		// �÷��̾� (����)
		RanObject mObstacle;

		std::vector<GameObject*> mGameObjects;
	};
}

