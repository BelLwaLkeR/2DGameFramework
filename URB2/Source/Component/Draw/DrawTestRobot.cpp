#include "DrawTestRobot.h"
#include <Source/Framework/Device/Renderer/ImageRenderer/eDrawLayer.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/Shader/ShaderManager.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/Shader/NormalMapShader.h>


component::DrawTestRobot::DrawTestRobot(){
	m_ImageParameters = framework::ImageParameters(framework::eDrawLayer::FIELD, "testRobot", { 32, 32 }, 1);
}

component::DrawTestRobot::~DrawTestRobot(){
}

void component::DrawTestRobot::draw(){
	SGLT_SHADER_MANAGER->attachShader<framework::NormalMapShader>(&m_pImageData);
}
