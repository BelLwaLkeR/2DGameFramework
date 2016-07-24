#pragma once
#include <map>
#include <Source/Framework/Device/Input/eInputCode.h>

/**
* @class		DxLibGamePad
* @namespace	framework
* @brief		DxLibのゲームパッド入力用ラッパクラス
* @author		大森 健司
*/


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