#include "GamePadInfomationMediator.h"

std::map<framework::eInputCode, framework::ePadButtonCode> framework::GamePadInfomationMediator::m_InputCodeMap = {
		{ { framework::eInputCode::UP		}, { framework::ePadButtonCode::UP		} },
		{ { framework::eInputCode::DOWN		}, { framework::ePadButtonCode::DOWN	} },
		{ { framework::eInputCode::LEFT		}, { framework::ePadButtonCode::LEFT	} },
		{ { framework::eInputCode::RIGHT	}, { framework::ePadButtonCode::RIGHT	} },
		{ { framework::eInputCode::ATTACK	}, { framework::ePadButtonCode::A		} },
		{ { framework::eInputCode::SKILL	}, { framework::ePadButtonCode::B		} },
		{ { framework::eInputCode::APEAL	}, { framework::ePadButtonCode::X		} },
		{ { framework::eInputCode::EXIT		}, { framework::ePadButtonCode::BACK	} }
	};


framework::GamePadInfomationMediator::GamePadInfomationMediator(){
}

framework::GamePadInfomationMediator::~GamePadInfomationMediator(){

}

int framework::GamePadInfomationMediator::getDeviceNo(int padNo){
	return DxLibGamePadInfomation::getDeviceNo(padNo);
}

int framework::GamePadInfomationMediator::getPadButtonCode(eInputCode code){
	return DxLibGamePadInfomation::getPadButtonNo(m_InputCodeMap[code]);
}
