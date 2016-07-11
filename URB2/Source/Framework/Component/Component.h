#pragma once
#include <Source/Utility/SmartPtr.h>
#include <Source/Framework/Entity/EntityInfomation.h>
namespace framework {
	class Component
	{
	public:
		Component();
		Component(util::WeakPtr<EntityInfomation> entityInfo);
		~Component();

		void setEntityInfomation(util::WeakPtr<EntityInfomation> entityInfomation);
	protected:
		util::WeakPtr<EntityInfomation> m_pEntityInfomation;

	private:
	};
}