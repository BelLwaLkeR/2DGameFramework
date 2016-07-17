#include "ImageData.h"

util::ImageData::ImageData(){
	ImageData(-1, -1);
}

util::ImageData::ImageData(const image_t & imageData, const pshader_t & shaderData, const Vector2 & oneImageSize, int imageNum){

}

void util::ImageData::setVertex(const Vector2& position){
	for (int i = 0; i < 6; ++i) {
		vertex[i].pos	= VGet((i % 2)*size.getIntX() + position.getIntX(), (((i + 1) / 3) % 2)*size.getIntY() + size.getIntY(), 0);
		vertex[i].rhw	= 1.f;
		vertex[i].dif	= GetColorU8(255, 255, 255, 255);
		vertex[i].spc	= GetColorU8(0, 0, 0, 0);
		vertex[i].u		= (float)(i % 2);
		vertex[i].su	= (float)(i % 2);
		vertex[i].v		= (float)(((i + 1) / 3) % 2);
		vertex[i].sv	= (float)(((i + 1) / 3) % 2);
	}
}


