#pragma once

#include <map>
#include <list>
#include <Source/Utility/Singleton.h>
#include <Source/Utility/SmartPtr.h>
#include <Source/Framework/Renderer/ImageRenderer/eDrawLayer.h>
#include <Source/Framework/Renderer/ImageRenderer/Screen.h>

#define SGLT_TASK_MANAGER framework::TaskManager::getInstance()

namespace framework {
	class UpdateComponent;
	class DrawComponent;
	class TaskManager: public util::Singleton<TaskManager>
	{
	public:
		TaskManager();
		~TaskManager();

		void initialize() override;
		void addUpdateTask(util::WeakPtr<UpdateComponent> task);
		void addDrawTask(eDrawLayer layer, util::WeakPtr<DrawComponent> task);
		void removeUpdateTask(util::WeakPtr<UpdateComponent> task);
		void removeDrawTask(eDrawLayer layer, util::WeakPtr<DrawComponent> task);
		void clearAllTask();
		void updateTask();
		void drawTask();

	private:
		std::list<util::WeakPtr<UpdateComponent>>							m_pUpdateTaskList;
		std::map<eDrawLayer, std::list<util::WeakPtr<DrawComponent>>>		m_pDrawTaskList;
		Screen																m_Screen;

		void drawTaskLayerd(eDrawLayer layer);
		bool isInUpdateTaskList(util::WeakPtr<UpdateComponent> task);
		bool isInDrawTaskList(util::WeakPtr<DrawComponent> task);
		bool isInDrawTaskList(eDrawLayer layer, util::WeakPtr<DrawComponent> task);
	};
}