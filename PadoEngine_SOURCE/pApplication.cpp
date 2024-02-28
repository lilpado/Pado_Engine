#include "pApplication.h"

namespace p
{
	Application::Application()
	{
		mHwnd = nullptr;
		mHdc = nullptr;
	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		mPlayer.SetPosition(0.0f, 0.0f);
		mPlayer2.SetPosition(0.0f, 0.0f);
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		mPlayer.Update();
		mPlayer2.Update();
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		mPlayer.Render(mHdc);
		mPlayer2.Render(mHdc);
	}
}