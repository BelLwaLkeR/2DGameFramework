#pragma once

#include <DxLib.h>
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>
namespace util {
	class ImageData;
}

namespace framework {
	class DxLibDrawShader{
	public:
		DxLibDrawShader();
		~DxLibDrawShader();
		static void drawShader(util::screen_t* pScreen,const util::ImageData& imageData);
	private:
		void setShader(util::pshader_t);
		void deleteShader(util::pshader_t);
	};

}