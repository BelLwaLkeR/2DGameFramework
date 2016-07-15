#pragma once

#include <bitset>
#include <map>
#include <Source/Framework/Device/Input/IInputDevice.h>
#include <Source/Framework/Device/Input/GamePad/ePadButtonCode.h>
#include <Source/Utility/SmartPtr.h>

namespace framework {
	class DxLibGamePad;
	class GamePad: public IInputDevice
	{
	public:
		GamePad();
		GamePad(int padNo);
		~GamePad();
		void setupDxLibGamePad(util::WeakPtr<DxLibGamePad> pDxLibGamePad);
		void update()							override;
		bool isKeyDown(eInputCode inputCode)	override;
		bool isKeyUp(eInputCode inputCode)		override;
		bool isKeyPush(eInputCode inputCode)	override;
		bool isKeyRelease(eInputCode inputCode) override;

	private:
		int										m_PadNo;
		std::map<eInputCode, ePadButtonCode>	m_ButtonMap;
		util::WeakPtr<DxLibGamePad>				m_pDxLibGamePad;
		std::bitset<(int)eInputCode::_END_>		m_PreButtonState;
		std::bitset<(int)eInputCode::_END_>		m_CurButtonState;
		
		void updateCurButtonState();
		bool isDownCurState(eInputCode inputCode);
		bool isDownPreState(eInputCode inputCode);


	};
}