#pragma once

#include <DxLib.h>
#include <Source/Utility/Type/Vector2.h>
#include <Source/Utility/Type/Vector3.h>
#include <Source/Utility/Type/Color.h>

namespace util {
	class DxLibConverter
	{
	public:
		DxLibConverter();
		~DxLibConverter();

		static FLOAT2 convertToFLOAT2	(const util::Vector2&	value);
		static FLOAT3 convertToFLOAT3	(const util::Vector3&	value);
		static FLOAT4 convertToFLOAT4	(const util::Vector2&	value, float z = 0.f, float w = 0.f);
		static FLOAT4 convertToFLOAT4	(const util::Vector3&	value, float w = 0.f);
		static FLOAT4 convertToFLOAT4	(const util::Color&		value);
	private:

	};
}


