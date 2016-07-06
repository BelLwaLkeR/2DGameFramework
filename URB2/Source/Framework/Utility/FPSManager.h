#pragma once
#include <Windows.h>
#include <vector>
namespace util {
	class FPSManager{
	public:
		FPSManager(unsigned int fps=60, unsigned int averageRecordSec=5);
		~FPSManager();
		void	wait();
		void	changeFPS(unsigned int fps);
		void	changeAverageRecordSec(unsigned int averageRecordSec);
		float	getAverageFPS();

	private:
		unsigned int				m_FPS;
		unsigned int				m_CountNowSec;
		DWORD						m_SecStartTime;
		std::vector<unsigned int>	m_RecordFPS;
		unsigned int				m_CountRecordSec;

		void	resetAverageFps();
		void	resetAverageRecordSec(unsigned int averageRecordSec);
		void	setStartSec();
		DWORD	calcWaitTime();

	};
}


