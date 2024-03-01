#include "pApplication.h"
#include "pInput.h"

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
		mPlayerRED.SetPosition(0.0f, 0.0f);
		mObstacle.SetPosition(0.0f, 0.0f);

		Input::Initialize();
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

		mPlayer.Update();
		mPlayerRED.UpdateRED();
		mObstacle.Update(mHwnd);
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{

		mPlayer.Render(mHdc);
		mPlayerRED.RenderRED(mHdc);
		mObstacle.Render(mHdc);
	}
}