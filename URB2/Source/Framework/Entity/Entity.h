#pragma once

#include <list>
#include <Source/Utility/SmartPtr.h>
#include <Source/Framework/Entity/EntityInfomation.h>
#include <Source/Framework/Component/Component.h>
#include <Source/Utility/Algorithm.h>

namespace framework {
	class Entity{
	public:
		Entity()	{}
		~Entity()	{}
		void addComponent(const std::string& componentName);
		void addParent(util::WeakPtr<Entity> parent);
		void addChild(util::WeakPtr<Entity> child);
		const util::WeakPtr<Entity>&			getParent();
		const std::list<util::WeakPtr<Entity>>&	getChildList();
		const EntityInfomation&					getInfomation();

	private:
		std::list<util::SharedPtr<Component>>	m_pComponentList;
		util::SharedPtr<EntityInfomation>		m_pInfomation;
		util::WeakPtr<Entity>					m_pParent;
		std::list<util::WeakPtr<Entity>>		m_pChildList;



		//template�֐�
	public:
		template<typename ComponentType>
		void addComponent() {
			m_pComponentList.emplace_back(SGLT_COMPONENTFACTORY->create<ComponentType>(m_pInfomation));
		}

		template<typename ComponentType>
		util::WeakPtr<ComponentType> getComponent() const {
			for (auto& component : m_pComponentList) {
				if (dynamic_cast<ComponentType*>(component.get() == nullptr)) { continue; }
				return component;
			}
			return util::WeakPtr<ComponentType>();
		}
	};
}