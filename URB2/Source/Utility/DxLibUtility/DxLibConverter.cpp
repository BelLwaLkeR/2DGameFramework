#include "DxLibConverter.h"

FLOAT2 util::DxLibConverter::convertToFLOAT2(const util::Vector2 & value){
	FLOAT2 tmp;
	tmp.u = value.X;
	tmp.v = value.Y;
	return tmp;
}

FLOAT3 util::DxLibConverter::convertToFLOAT3(const util::Vector3 & value){
	FLOAT3 tmp;
	tmp.x = value.X;
	tmp.y = value.Y;
	tmp.z = value.Z;
	return tmp;
}

FLOAT4 util::DxLibConverter::convertToFLOAT4(const util::Vector2 & value, float z, float w){
	FLOAT4 tmp;
	tmp.x = value.X;
	tmp.y = value.Y;
	tmp.z = z;
	tmp.w = w;
	return tmp;
}


FLOAT4 util::DxLibConverter::convertToFLOAT4(const util::Vector3 & value, float w){
	FLOAT4 tmp;
	tmp.x = value.X;
	tmp.y = value.Y;
	tmp.z = value.Z;
	tmp.w = w;
	return tmp;
}

FLOAT4 util::DxLibConverter::convertToFLOAT4(const util::Color & value){
	FLOAT4 tmp;
	tmp.x = value.getRedF();
	tmp.y = value.getGreenF();
	tmp.z = value.getBlueF();
	tmp.w = value.getAlphaF();
	return tmp;
}
