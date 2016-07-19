#pragma once

#include <DxLib.h>
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>
namespace framework {
	class DxLibDrawShader
	{
	public:
		DxLibDrawShader();
		~DxLibDrawShader();
		static void drawShader(util::);
	private:
		void setShader(util::pshader_t);
		void deleteShader(util::pshader_t);
	};

}