#pragma once
#include <Source/Utility/SmartPtr.h>

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

	private:
		static SharedPtr<T> m_pInstance;

		Singleton() {}

		Singleton(const Singleton& other) {}

		const Singleton& operator=(const Singleton& other) {}

		static void createInstance() {
			m_pInstance = std::make_shared<T>();
			m_pInstance->initialize();
		}
	};

}
