#pragma once
#include <map>
#include <Source/Framework/Device/Input/eInputCode.h>
#include <Source/Framework/Device/Input/GamePad/eGamePadCode.h>

namespace framework {
	class DxLibGamePad
	{
	public:
		DxLibGamePad();
		~DxLibGamePad();
		void setPadNo(int padNo);
		void updateGamePadState();

	private:
		int m_PadNo;

		void setupButtonMap();

	};
}