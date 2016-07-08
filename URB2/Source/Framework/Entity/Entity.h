#pragma once

#include <vector>
#include <Source/Utility/SmartPtr.h>
#include <Source/Framework/Entity/EntityInfomation.h>
#include <Source/Framework/Component/Component.h>
#include <Source/Utility/Algorithm.h>

namespace framework {
	class Entity
	{
	public:
		Entity() {}
		~Entity() {}
		template<typename ComponentType>
		void addComponent();
		template<typename ComponentType>
		util::WeakPtr<ComponentType> getComponent() const;

	private:
		std::vector<util::SharedPtr<Component>> m_pComponentList;
		util::SharedPtr<EntityInfomation> m_pInfomation;

	};

	template<typename ComponentType>
	inline void Entity::addComponent(){
		
	}

	template<typename ComponentType>
	inline util::WeakPtr<ComponentType> Entity::getComponent() const{
		auto& itr = util::Algorithm::Find<Component>(m_pComponentList, [&](Component& component) {
			return dynamic_cast<ComponentType*>(component.get()) != nullptr;
		});
		if (itr == m_pComponentList.end()) { return util::WeakPtr<ComponentType>(); }

		return util::WeakPtr<ComponentType>(m_pComponentList[itr]);
	}
}