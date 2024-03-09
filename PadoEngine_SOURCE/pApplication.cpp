#include "pApplication.h"
#include "pInput.h"

namespace p
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
		, mGameObjects{}
	{

	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);

		for (size_t i = 0; i < 100; i++)
		{
			GameObject* gameObj = new GameObject();
		
			gameObj->SetPosition(rand() % 1600, rand() % 900);
			mGameObjects.push_back(gameObj);
		}

		mObstacle.SetPosition(0.0f, 0.0f);

		initializeEtc();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		Input::Update();
		Time::Update();

		for (size_t i = 0; i < mGameObjects.size(); i++)
		{
			mGameObjects[i]->Update();
		}

		//mPlayer.Update();
		//mPlayerRED.UpdateRED();
		mObstacle.Update(mHwnd);
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		clearRenderTarget();

		Time::Render(mBackHdc);
		
		for (size_t i = 0; i < mGameObjects.size(); i++)
		{
			mGameObjects[i]->Render(mBackHdc);
		}

		//mPlayer.Render(mBackHdc);
		//mPlayerRED.RenderRED(mBackHdc);
		mObstacle.Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
	}

	void Application::clearRenderTarget()
	{
		//clear
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void Application::copyRenderTarget(HDC src, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight
			, src, 0, 0, SRCCOPY);
	}


	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0
			, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		// 윈도우 해상도에 맞는 백버퍼 (도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// 백버퍼를 가리킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void Application::initializeEtc()
	{
		Input::Initialize();
		Time::Initialize();
	}
}