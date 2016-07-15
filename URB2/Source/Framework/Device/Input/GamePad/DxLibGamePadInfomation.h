#pragma once
#include <map>
#include <Source/Framework/Device/Input/GamePad/ePadButtonCode.h>

namespace framework {
	class DxLibGamePadInfomation{
	public:
		DxLibGamePadInfomation() {}
		~DxLibGamePadInfomation() {}

	protected:
		static int getDeviceNo(int padNo);
		static int getPadButtonNo(ePadButtonCode code);

	private:
		static std::map<ePadButtonCode, int>	m_ButtonNumberMap;
	};
}



