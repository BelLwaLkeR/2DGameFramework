#include "ImageData.h"
#include <Source/Utility/DxLibUtility/DxLibImageLoader.h>
#include <Source/Framework/Define.h>


util::ImageData::ImageData(){
}

util::ImageData::ImageData(WeakPtr<Vector2> pPosition, const std::string & imageName, const Vector2 & oneImageSize, int imageNum){
	m_Texture			= util::DxLibImageLoader::loadImageDiv(IMAGEDATA_DIR + imageName + TEXTURE_FOOTER		, oneImageSize, imageNum);
	m_NormalMap		= util::DxLibImageLoader::loadImageDiv(IMAGEDATA_DIR + imageName + NORMALMAP_FOOTER		, oneImageSize, imageNum);
	m_ReflectionMap	= util::DxLibImageLoader::loadImageDiv(IMAGEDATA_DIR + imageName + REFLECTIONMAP_FOOTER	, oneImageSize, imageNum);
	m_Size			= oneImageSize;
	m_pPosition		= pPosition;
	setup();
}

util::vertex_t* util::ImageData::getVertexPointer() const{
	reloadVertex();
	return &m_Vertex[0];
}

const util::image_t & util::ImageData::getTexture(){
	return m_Texture[0];
}

const util::image_t & util::ImageData::getNormalMap(){
	return m_NormalMap[0];
}

const util::image_t & util::ImageData::getReflectionMap(){
	return m_ReflectionMap[0];
}

const util::Vector2 & util::ImageData::getSize(){
	return m_Size;
}

void util::ImageData::setup(){
	for (int i = 0; i < 6; ++i) {
		m_Vertex[i].rhw	= 1.f;
		m_Vertex[i].dif	= GetColorU8(255, 255, 255, 255);
		m_Vertex[i].spc	= GetColorU8(0, 0, 0, 0);
		m_Vertex[i].u	= (float)(i % 2);
		m_Vertex[i].su	= (float)(i % 2);
		m_Vertex[i].v	= (float)(((i + 1) / 3) % 2);
		m_Vertex[i].sv	= (float)(((i + 1) / 3) % 2);
	}
}

void util::ImageData::reloadVertex() const{
	for (int i = 0; i < 6; ++i) {
		m_Vertex[i].pos = VGet((i % 2)*m_Size.getIntX() + m_pPosition->getIntX(), (((i + 1)/3)%2)*m_Size.getIntY() +m_pPosition->getIntY(), 0);
	}
}

