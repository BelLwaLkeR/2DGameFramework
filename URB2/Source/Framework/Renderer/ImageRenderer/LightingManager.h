#pragma once
#include <list>
#include <Source/Utility/SmartPtr.h>


namespace framework {
	class LightingManager
	{
	public:
		LightingManager();
		~LightingManager();



	private:
		std::list<util::WeakPtr<int>>	m_pShaderObjectList;
	};
}