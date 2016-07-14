#pragma once

#include <list>
#include <Source/Utility/SmartPtr.h>
#include <Source/Framework/Entity/EntityInfomation.h>
#include <Source/Framework/Component/ComponentFactory.h>
#include <algorithm>

namespace framework {
	class Component;
	class Entity{
	public:
		Entity();
		~Entity();
		void addComponent(const std::string& componentName);
		void addParent(util::WeakPtr<Entity> parent);
		void addChild(util::WeakPtr<Entity> child);
		const util::WeakPtr<Entity>&				getParent()		const;
		const std::list<util::WeakPtr<Entity>>&		getChildList()	const;
		const util::WeakPtr<Component>				getComponent(Component* component)	const;
		const std::list<util::WeakPtr<Component>>&	getComponentList()		const;

		template<typename ComponentType>
		const util::WeakPtr<Component> getComponent()			const;

	private:
		std::list<util::SharedPtr<Component>>	m_pComponentList;
		util::SharedPtr<EntityInfomation>		m_pInfomation;
		util::WeakPtr<Entity>					m_pParent;
		std::list<util::WeakPtr<Entity>>		m_pChildList;
		util::SharedPtr<Entity>					m_pEntity;



		//template関数
	public:
		template<typename ComponentType>
		void addComponent() {
			util::WeakPtr<Component> component = SGLT_COMPONENTFACTORY->createComponent<ComponentType>();
			if (!component.lock()) {
				assert(!"コンポーネントが見つかりません。");
				return;
			}
			m_pComponentList.emplace_back(component);
		}

		template<typename CastType>
		util::WeakPtr<CastType> getComponentCast(Component* component) {
			auto& itr = std::find_if(m_pComponentList.begin(), m_pComponentList.end(), [&](util::SharedPtr<Component> thisComponent) {
				return thisComponent.get() == component;
			});
			if (itr == m_pComponentList.end()) {
				assert(!"コンポーネントが見つかりません。");
				return util::WeakPtr<CastType>();
			}
			return std::static_pointer_cast<CastType>(*itr);


		}

		template<typename ComponentType>
		util::WeakPtr<ComponentType> getComponent() const {
			for (auto& component : m_pComponentList) {
				if (dynamic_cast<ComponentType*>(component.get() == nullptr)) { continue; }
				return component;
			}
			assert(!"コンポーネントが見つかりません。");
			return util::WeakPtr<ComponentType>();
		}
	};
}