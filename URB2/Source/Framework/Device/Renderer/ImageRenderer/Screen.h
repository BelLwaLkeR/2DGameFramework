#pragma once

#include <Source/Utility/Singleton.h>
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/DxLibImageRenderer.h>

/**
* @class		IPいぇScreen
* @namespace	framework
* @brief		レンダスクリーン管理・切り替え用クラス
* @author		大森 健司
*/

namespace framework {
	class IPixelShader;
	class Screen{
	public:
		Screen() ;
		~Screen();
		void initialize();
		void changeDrawTargetGameScreen();
		void drawToApplication();

	private:
		util::screen_t		m_GameScreen;
		DxLibImageRenderer	m_DxLibImageRenderer;

		void setupGameScreen();
		void clearScreen();
	};
}



