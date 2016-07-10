#pragma once
#include <vector>
#include <Source/Utility/SmartPtr.h>
#include <Source/Framework/Entity/Entity.h>
#include <Source/Framework/Component/ComponentFactory.h>

namespace framework {
	class EntityManager
	{
	public:
		EntityManager();
		~EntityManager();
		
		void addEntity(const std::vector<Component>& components);
		void addEntity(util::SharedPtr<Component> components);
		void removeEntity();


	private:
		std::vector<util::SharedPtr<Entity>> m_pEntityList;
		
	};
}