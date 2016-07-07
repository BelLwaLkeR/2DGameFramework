#pragma once

#include <Source/Framework/Task/TaskManager.h>
namespace framework {
	class IDrawTask{
	public:
		IDrawTask();
		~IDrawTask();
		virtual void draw()		= 0;

	protected:
		template<typename T>
		virtual void active<T>();
		virtual void deActive()	= 0;
	};
	template<typename T>
	inline void IDrawTask::active(){
		SGLT_TASKMANAGER->addDrawTask(util::WeakPtr<T>());
	}
}