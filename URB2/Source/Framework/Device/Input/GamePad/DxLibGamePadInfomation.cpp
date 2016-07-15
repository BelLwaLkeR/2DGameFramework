#include "DxLibGamePadInfomation.h"
#include <DxLib.h>

std::map<framework::ePadButtonCode, int> framework::DxLibGamePadInfomation::m_ButtonNumberMap = {
	{ { framework::ePadButtonCode::UP	}, { PAD_INPUT_UP		} },
	{ { framework::ePadButtonCode::DOWN	}, { PAD_INPUT_DOWN		} },
	{ { framework::ePadButtonCode::LEFT	}, { PAD_INPUT_LEFT		} },
	{ { framework::ePadButtonCode::RIGHT}, { PAD_INPUT_RIGHT	} },
	{ { framework::ePadButtonCode::A	}, { PAD_INPUT_1		} },
	{ { framework::ePadButtonCode::B	}, { PAD_INPUT_2		} },
	{ { framework::ePadButtonCode::X	}, { PAD_INPUT_3		} },
	{ { framework::ePadButtonCode::BACK	}, { PAD_INPUT_5		} }
};

int framework::DxLibGamePadInfomation::getDeviceNo(int padNo){
	return DX_INPUT_PAD1 + padNo;
}

int framework::DxLibGamePadInfomation::getPadButtonNo(ePadButtonCode code){
	return DxLibGamePadInfomation::m_ButtonNumberMap[code];
}




