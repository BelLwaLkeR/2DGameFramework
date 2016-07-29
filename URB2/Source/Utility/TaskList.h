#pragma once

#include <list>
#include <Source/Utility/SmartPtr.h>

/**
* @struct		TaskList
* @namespace	util
* @brief		タスクの追加・削除を一括で行うためのクラス
* @author		大森 健司
*/


namespace util {
	template<typename TaskType>
	class TaskList {
	public:
		TaskList();
		~TaskList();
		const std::list<util::WeakPtr<TaskType>>& getTaskList();
		void addTask(util::WeakPtr<TaskType> task);
		void removeTask(util::WeakPtr<TaskType> task);
		void refleshTask();
		void clearAllTask();

	private:
		std::list<util::WeakPtr<TaskType>> m_pTaskList;
		std::list<util::WeakPtr<TaskType>> m_pAddList;
		std::list<util::WeakPtr<TaskType>> m_pRemoveList;

		void clearTaskList();
		void clearAddList();
		void clearRemoveList();
		void registorTask();
		void deregistorTask();
	};


	template<typename TaskType>
	inline TaskList<TaskType>::TaskList():m_pTaskList(), m_pAddList(), m_pRemoveList(){
	}

	template<typename TaskType>
	inline TaskList<TaskType>::~TaskList(){
		clearAllTask();
	}

	template<typename TaskType>
	inline const std::list<util::WeakPtr<TaskType>>& TaskList<TaskType>::getTaskList(){
		return m_pTaskList;
	}

	template<typename TaskType>
	inline void TaskList<TaskType>::addTask(util::WeakPtr<TaskType> task){
		m_pTaskList.emplace_back(task);
	}

	template<typename TaskType>
	inline void TaskList<TaskType>::removeTask(util::WeakPtr<TaskType> task){
		m_pTaskList.emplace_back(task);
	}

	template<typename TaskType>
	inline void TaskList<TaskType>::refleshTask(){
		registorTask();
		clearAddList();
	}

	template<typename TaskType>
	inline void TaskList<TaskType>::clearAllTask(){
		clearAddList();
		clearRemoveList();
		clearTaskList();
	}

	template<typename TaskType>
	inline void TaskList<TaskType>::clearTaskList(){
		m_pTaskList.clear();
	}

	template<typename TaskType>
	inline void TaskList<TaskType>::clearAddList(){
		m_pAddList.clear();
	}

	template<typename TaskType>
	inline void TaskList<TaskType>::clearRemoveList(){
		m_pRemoveList.clear();
	}

	template<typename TaskType>
	inline void TaskList<TaskType>::registorTask(){
		if (m_pAddList.empty()) { return; }
		for (auto& task : m_pAddList) {
			m_pTaskList.emplace_back(task);
		}
		clearAddList();
	}

	template<typename TaskType>
	inline void TaskList<TaskType>::deregistorTask(){
		if (m_pRemoveList.empty()) { return; }
		for (auto& task : m_pRemoveList) {
			auto& itr = std::find(m_pTaskList, task);
			if (itr == m_pTaskList.end()) { continue; }
			m_pTaskList.erase(itr);
		}
		clearRemoveList();
	}
}

