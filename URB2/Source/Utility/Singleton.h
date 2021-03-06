#pragma once
#include <Source/Utility/SmartPtr.h>

/**
* @class		Singleton<>
* @namespace	util
* @brief		継承先をシングルトンにするクラス
* @author		大森 健司
*/


namespace util {
	template<typename T>
	class Singleton {
	public:

		static WeakPtr<T> getInstance() {
			if (!m_pInstance) { createInstance(); }
			return m_pInstance;
		}

		void reset() {
			m_pInstance->finalize();
			m_pInstance.reset();
		}

		virtual void initialize() {}
		virtual void finalize() {}


	protected:
		Singleton() {}

	private:
		static SharedPtr<T> m_pInstance;
		Singleton(const Singleton& other) {}

		const Singleton& operator=(const Singleton& other) {}
		static void createInstance() {
			m_pInstance = util::makeShared<T>();
			m_pInstance->initialize();
		}

	};
	template<typename T>
	SharedPtr<T> Singleton<T>::m_pInstance =  util::makeShared<T>();
}
