#pragma once
#include "..\PadoEngine_SOURCE\pSceneManager.h"
#include "pPlayScene.h"

// '참조' 사용 중이라 지금은 괜찮지만, 아니라면 include한 '헤더 파일' 말고
// cpp 파일도 쓰기위해 아래처럼 해줘야한다.
//#ifdef _DEBUG
//#pragma comment(lib, "..\x64\Debug\PadoEngine_Window.lib")
//#else
//#pragma comment(lib, "..\x64\Release\PadoEngine_Window.lib")
//#endif

namespace p
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"PlayScene");
		//SceneManager::CreateScene<TitleScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}