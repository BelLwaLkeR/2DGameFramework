#pragma once

#include <Source/Utility/Singleton.h>
#include <Source/Utility/SmartPtr.h>
#include <vector>

#define SGLT_TASKMANAGER framework::TaskManager::getInstance()

namespace framework {
	class IUpdateTask;
	class IDrawTask;
	class TaskManager: public util::Singleton<TaskManager>
	{
	public:
		TaskManager();
		~TaskManager();

		void addUpdateTask(util::SharedPtr<IUpdateTask> task);
		void addDrawTask(util::SharedPtr<IDrawTask> task);
		void removeUpdateTask(util::SharedPtr<IUpdateTask> task);
		void removeDrawTask(util::SharedPtr<IDrawTask> task);
		void updateTask();
		void drawTask();

	private:
		std::vector<util::SharedPtr<IUpdateTask>> m_pUpdateTaskList;
		std::vector<util::SharedPtr<IDrawTask>> m_pDrawTaskList;
	};
}