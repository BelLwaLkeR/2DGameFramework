#pragma once
#include <vector>
#include <Source/Utility/SmartPtr.h>
#include <Source/Framework/Entity/Entity.h>
#include <Source/Framework/Component/ComponentFactory.h>
#include <Source/Utility/Singleton.h>

/**
* @class		EntityManager
* @inheritance	Singleton<EntityManager>
* @namespace	framework
* @brief		Entity‚ğ‚Ü‚Æ‚ß‚éƒNƒ‰ƒX
* @author		‘åX Œ’i
*/

#define SGLT_ENTITY_MANAGER framework::EntityManager::getInstance()

namespace framework {
	class EntityManager: public util::Singleton<EntityManager>
	{
	public:
		EntityManager();
		~EntityManager();
		
		util::WeakPtr<Entity> addEntity(const EntityInfomation& entityInfomation);
 		util::WeakPtr<Entity> addEntity(const EntityInfomation& entityInfomation, const std::string& componentName);
		util::WeakPtr<Entity> addEntity(const EntityInfomation& entityInfomation, const std::vector<std::string>& componentNameList);
		util::WeakPtr<Entity> getEntity(Entity* entity);
		void clearEntity();

	private:
		std::vector<util::SharedPtr<Entity>> m_pEntityList;
		
	};
}