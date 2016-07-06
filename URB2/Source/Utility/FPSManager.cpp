#include "FPSManager.h"
#include <chrono>


util::FPSManager::FPSManager(unsigned int fps, unsigned int averageRecordSec):m_FPS(fps){
	resetAverageRecordSec(averageRecordSec);
}

util::FPSManager::~FPSManager(){

}

void util::FPSManager::wait(){
	Sleep(calcWaitTime());
}

void util::FPSManager::changeFPS(unsigned int fps){
	resetAverageFps();
}

void util::FPSManager::changeAverageRecordSec(unsigned int averageRecordSec){

}

void util::FPSManager::resetAverageFps(){

}

float util::FPSManager::getAverageFPS(){
	int		count	= 0;
	float	sumFPS	= 0.f;
	for (auto& fps: m_RecordFPS) {
		if (fps == -1) { continue; }
		sumFPS += fps;
		++count;
	}
	return (count>0)? sumFPS/count: 0.f;
}

void util::FPSManager::resetAverageRecordSec(unsigned int averageRecordSec){
	m_RecordFPS.assign(averageRecordSec, -1);
}

void util::FPSManager::setStartSec(){

}

DWORD util::FPSManager::calcWaitTime(){
	DWORD nextSecTime = m_SecStartTime + 1000;
	
	return 0;
}
