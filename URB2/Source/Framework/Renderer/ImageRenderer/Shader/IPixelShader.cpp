#include "IPixelShader.h"

framework::IPixelShader::IPixelShader(){

}

framework::IPixelShader::IPixelShader(util::WeakPtr<util::Vector2> pPosition){
	m_pPosition = pPosition;
}

framework::IPixelShader::~IPixelShader(){


}

void framework::IPixelShader::setPixelShader(util::WeakPtr<util::Vector2> pPosition){
	m_pPosition = pPosition;
}
