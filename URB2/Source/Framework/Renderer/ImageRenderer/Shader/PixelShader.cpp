//#include "PixelShader.h"
//#include <cassert>
//#include <Source/Framework/Define.h>
//#include <Source/Utility/DxLibUtility/DxLibPixelShaderLoader.h>
//
//
//framework::PixelShader::PixelShader(){
//	m_ShaderName = "";
//}
//
//framework::PixelShader::PixelShader(const std::string & shaderName){
//	setShaderName(shaderName); 
//}
//
//framework::PixelShader::~PixelShader(){
//	
//}
//
//void framework::PixelShader::setShaderName(const std::string& shaderName){
//	m_ShaderName= shaderName;
//}
//
//util::pshader_t framework::PixelShader::loadShader(){
//	m_PixelShader = util::DxLibShaderLoader::loadPixelShader(m_ShaderName);
//	return m_PixelShader;
//}
//
//void framework::PixelShader::deleteShader(){
//	util::DxLibShaderLoader::deletePixelShader(m_PixelShader);
//	m_PixelShader = EMPTY_VALUE;
//	return;
//}
//
