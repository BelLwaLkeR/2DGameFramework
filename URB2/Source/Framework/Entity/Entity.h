#pragma once

#include <list>
#include <Source/Utility/SmartPtr.h>
#include <Source/Framework/Entity/EntityInfomation.h>
#include <Source/Framework/Component/Component.h>
#include <Source/Utility/Algorithm.h>
#include <Source/Framework/Component/ComponentFactory.h>

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
		const util::WeakPtr<EntityInfomation>	getInfomation();

	private:
		std::list<util::SharedPtr<Component>>	m_pComponentList;
		util::SharedPtr<EntityInfomation>		m_pInfomation;
		util::WeakPtr<Entity>					m_pParent;
		std::list<util::WeakPtr<Entity>>		m_pChildList;



		//templateä÷êî
	public:
		template<typename ComponentType>
		void addComponent() {
			m_pComponentList.emplace_back(SGLT_COMPONENTFACTORY->createComponent<ComponentType>(m_pInfomation));
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