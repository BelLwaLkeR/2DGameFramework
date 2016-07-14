#include "ImageData.h"

util::ImageData::ImageData(){
	
}

util::ImageData::ImageData(const image_t & imageData, const pshader_t & shaderData){
	image	= imageData;
	shader	= shaderData;
}
