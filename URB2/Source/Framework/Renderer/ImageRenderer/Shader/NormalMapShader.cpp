#include "NormalMapShader.h"
#include <Source/Utility/Type/ImageData.h>
#include <Source/Framework/Renderer/ImageRenderer/DxLibImageRenderer.h>
#include <Source/Framework/Renderer/ImageRenderer/Shader/ShaderManager.h>
#include <Source/Framework/Renderer/ImageRenderer/Shader/DxLibShader.h>
#include <Source/Utility/DxLibUtility/DxLibPixelShaderLoader.h>

framework::NormalMapShader::NormalMapShader(){
	m_Shader = util::DxLibShaderLoader::loadPixelShader("NormalMapShader");
}

framework::NormalMapShader::~NormalMapShader(){

}

void framework::NormalMapShader::attachShader(util::SharedPtr<util::ImageData>* targetImage){
//	DxLibShaderFunction::setUsePixelShader(m_Shader);
//	DxLibShaderFunction::setTexture(0, (*targetImage)->getTexture());
//	DxLibShaderFunction::setTexture(1, (*targetImage)->getNormalMap());
//	DxLibShaderFunction::setTexture(2, (*targetImage)->getReflectionMap());
//
//
////	std::array<float, 3> relativeLightPosition = { 100 - m_pImageData->getPosition().X, 100 - m_pImageData->getPosition().Y, 0 };
//	std::vector<float>		relativeLightPosition	= { 100 - (*targetImage)->getPosition().X, 100 - (*targetImage)->getPosition().Y, 0 };
//	std::array<float, 3>	ambientLightColor		= { 1.0f, 0.2f, 0.2f };
//	std::array<float, 3>	LightColor				= { 1.f, 1.f, 1.f };
//
//
//
//	DxLibShaderFunction::setValue(0, (*targetImage)->getSize());
//	DxLibShaderFunction::setAmbientLight(2);
	DxLibShaderFunction::setLightColor(5, (*targetImage)->getPosition());
//	DxLibShaderFunction::setValueArray(8, relativeLightPosition);
//	DxLibShaderFunction::setValue(11, 5);
//	SetPSConstSFArray(2, &ambientLightColor[0], 3);
//
//
//	DrawPolygon2DToShader((*targetImage)->getVertexPointer(), 2);
//	DeleteShader(m_Shader);

	int imaHdl = (*targetImage)->getTexture();
	int nmlHdl = (*targetImage)->getNormalMap();
	int refHdl = (*targetImage)->getReflectionMap();

	ClearDrawScreen();
	//	DrawGraph(m_posX - m_sizeX/2, m_posY - m_sizeY/2,m_ImageHandle, FALSE);
	SetUsePixelShader(m_Shader);
	SetUseTextureToShader(0, imaHdl);
	SetUseTextureToShader(1, nmlHdl);
	SetUseTextureToShader(2, refHdl);


	std::array<float, 3> relativeLightPosition	= { 10	, 10,0 };
	std::array<float, 3> ambientLightColor		= { 0.f , 0.f , 0.3f };
	std::array<float, 3> LightColor				= { 1.f	, 1.f , 1.f };


	SetPSConstSF(0, 32);
	SetPSConstSF(1, 32);
	SetPSConstSFArray(2, &ambientLightColor[0], 3);
	SetPSConstSFArray(5, &LightColor[0], 3);
	SetPSConstSFArray(8, &relativeLightPosition[0], 3);
	SetPSConstSF(11, 5.f);

	//	printfDx("\t\t\t\t\t%f, %f, %f\n", m_pLight.lock()->getPosition().x, m_pLight.lock()->getPosition().y, m_pLight.lock()->getPosition().z);

	DrawPolygon2DToShader((*targetImage)->getVertexPointer(), 2);
	DeleteShader(m_Shader);



}

void framework::NormalMapShader::deleteShader(){
	util::DxLibShaderLoader::deletePixelShader(m_Shader);
}
  