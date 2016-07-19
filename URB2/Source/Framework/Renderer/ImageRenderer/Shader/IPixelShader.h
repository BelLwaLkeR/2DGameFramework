#pragma once
#include <Source/Utility/Type/ImageData.h>
#include <Source/Utility/SmartPtr.h>

namespace framework {
	class IPixelShader{
	public:
		IPixelShader()	{}
		~IPixelShader()	{}


	private:
		util::WeakPtr<util::ImageData> test;
	};
}





