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

		void addUpdateTask(util::WeakPtr<IUpdateTask> task);
		void addDrawTask(util::WeakPtr<IDrawTask> task);
		void removeUpdateTask(util::WeakPtr<IUpdateTask> task);
		void removeDrawTask(util::WeakPtr<IDrawTask> task);
		void taskUpdate();
		void taskDraw();

	private:
		std::vector<util::WeakPtr<IUpdateTask>> m_pUpdateTaskList;
		std::vector<util::WeakPtr<IDrawTask>> m_pDrawTaskList;

		bool isInUpdateTaskList(util::WeakPtr<IUpdateTask> task);
		bool isInDrawTaskList(util::WeakPtr<IDrawTask> task);
	};
}