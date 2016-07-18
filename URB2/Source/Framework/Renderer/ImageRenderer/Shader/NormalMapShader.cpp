#include "NormalMapShader.h"
#include <Source/Utility/StringEditor.h>

framework::NormalMapShader::NormalMapShader(){
	PixelShader("NormalMapShader.pso");
}

framework::NormalMapShader::~NormalMapShader()
{
}

void framework::NormalMapShader::draw(const util::ImageData & image, const util::Vector2 & position){
	
}
