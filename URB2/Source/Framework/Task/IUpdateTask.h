#pragma once
#include <Source/Framework/Task/TaskManager.h>

namespace framework {
	class IUpdateTask {
	public:
		IUpdateTask() {}
		~IUpdateTask() {}
		virtual void update()	= 0;

	protected:
		template<typename T>
		void active();
		template<typename T>
		void deActive();
	private:


	};

	template<typename T>
	inline void IUpdateTask::active(){
		SGLT_TASKMANAGER->addUpdateTask(util::WeakPtr<T>(this));

	}

	template<typename T>
	inline void IUpdateTask::deActive(){
		SGLT_TASKMANAGER->removeUpdateTask(util::WeakPtr<T>(this));
	}
}