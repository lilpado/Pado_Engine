#pragma once
#include "..\PadoEngine_SOURCE\pSceneManager.h"
#include "pPlayScene.h"

// '����' ��� ���̶� ������ ��������, �ƴ϶�� include�� '��� ����' ����
// cpp ���ϵ� �������� �Ʒ�ó�� ������Ѵ�.
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