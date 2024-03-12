#pragma once
#include "..\PadoEngine_SOURCE\pScene.h"

namespace p
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


	private:
	};
}
