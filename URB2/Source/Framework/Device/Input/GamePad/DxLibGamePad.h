#pragma once
#include <map>
#include <Source/Framework/Device/Input/eInputCode.h>

namespace framework {
	class DxLibGamePad
	{
	public:
		DxLibGamePad();
		~DxLibGamePad();
		bool isKeyDown(int padNo, eInputCode code);

	private:
	};
}