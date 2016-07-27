#include "Screen.h"
#include <Source/Framework/Define.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/DxLibImageRenderer.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/Shader/IPixelShader.h>

framework::Screen::Screen(){
}

framework::Screen::~Screen(){
}

void framework::Screen::initialize(){
	setupGameScreen();
}

void framework::Screen::changeDrawTargetGameScreen(){
	DxLibImageRenderer::setDrawScreen(m_GameScreen);
	DxLibImageRenderer::clearScreen();

}

void framework::Screen::drawToApplication(){
	DxLibImageRenderer::setScreenAplicationBack();
	DxLibImageRenderer::clearScreen();
	DxLibImageRenderer::drawScreenForWindow(m_GameScreen);
	DxLibImageRenderer::screenFlip();
}

void framework::Screen::setupGameScreen(){
	m_GameScreen = DxLibImageRenderer::makeScreen({SCREEN_WIDTH, SCREEN_HEIGHT});
}

void framework::Screen::clearScreen(){
	DxLibImageRenderer::clearScreen();
}


