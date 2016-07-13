#pragma once

#include <Source/Utility/Singleton.h>
#include <Source/Utility/SmartPtr.h>

#include <list>

#define SGLT_TASKMANAGER framework::TaskManager::getInstance()

namespace framework {
	class UpdateComponent;
	class DrawComponent;
	class TaskManager: public util::Singleton<TaskManager>
	{
	public:
		TaskManager();
		~TaskManager();

		void addUpdateTask(util::WeakPtr<UpdateComponent> task);
		void addDrawTask(util::WeakPtr<DrawComponent> task);
		void removeUpdateTask(util::WeakPtr<UpdateComponent> task);
		void removeDrawTask(util::WeakPtr<DrawComponent> task);
		void clearAllTask();
		void updateTask();
		void drawTask();

	private:
		std::list<util::WeakPtr<UpdateComponent>>	m_pUpdateTaskList;
		std::list<util::WeakPtr<DrawComponent>>		m_pDrawTaskList;

		bool isInUpdateTaskList(util::WeakPtr<UpdateComponent> task);
		bool isInDrawTaskList(util::WeakPtr<DrawComponent> task);
	};
}