#include "GlobalParameters.h"

framework::GlobalParameters::GlobalParameters(){
}

framework::GlobalParameters::~GlobalParameters(){
}

void framework::GlobalParameters::update(){
	++m_GameCounter;
}

const unsigned long& framework::GlobalParameters::getGameCount(){
	return m_GameCounter;
}
