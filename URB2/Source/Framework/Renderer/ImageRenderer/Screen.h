#pragma once

#include <Source/Utility/Singleton.h>
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>
#include <Source/Framework/Renderer/ImageRenderer/DxLibImageRenderer.h>

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



