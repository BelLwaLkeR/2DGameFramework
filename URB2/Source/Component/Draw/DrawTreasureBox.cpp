#include "DrawTreasureBox.h"
#include <Source/Framework/Device/Renderer/ImageRenderer/eDrawLayer.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/Shader/ShaderManager.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/Shader/NormalMapShader.h>

component::DrawTreasureBox::DrawTreasureBox(){
	m_ImageParameters = framework::ImageParameters(framework::eDrawLayer::FIELD, "TreasureBox", { 32, 32 }, 1);
}

component::DrawTreasureBox::~DrawTreasureBox(){
}

void component::DrawTreasureBox::draw(){
	SGLT_SHADER_MANAGER->attachShader<framework::NormalMapShader>(&m_pImageData);

}
