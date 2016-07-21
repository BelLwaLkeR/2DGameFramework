#pragma once

#include <list>
#include <Source/Utility/SmartPtr.h>
#include <Source/Framework/Entity/EntityInfomation.h>
#include <Source/Framework/Component/ComponentFactory.h>
#include <Source/Framework/Define.h>
#include <algorithm>

namespace framework {
	class Component;
	class Entity{
	public:
		Entity(EntityInfomation entityInfomation = {});
		~Entity();
		void setMyself(util::WeakPtr<Entity> pMyselfEntity);
		void addComponent(const std::string& componentName);
		void addParent(util::WeakPtr<Entity> parent);
		void addChild(util::WeakPtr<Entity> child);
		const util::WeakPtr<Entity>&				getEntity()		const;
		const util::WeakPtr<Entity>&				getParent()		const;
		const std::list<util::WeakPtr<Entity>>&		getChildList()	const;
		const util::WeakPtr<Component>				getComponent(Component* component)	const;
		const std::list<util::WeakPtr<Component>>&	getComponentList()		const;

		template<typename ComponentType>
		const util::WeakPtr<Component> getComponent()			const;

	private:
		std::list<util::SharedPtr<Component>>	m_pComponentList;
		util::SharedPtr<EntityInfomation>		m_pInfomation;
		util::WeakPtr<Entity>					m_pEntity;
		util::WeakPtr<Entity>					m_pParent;
		std::list<util::WeakPtr<Entity>>		m_pChildList;



		//template関数
	public:
		template<typename ComponentType>
		void addComponent() {
			util::WeakPtr<Component> component = SGLT_COMPONENT_FACTORY->createComponent<ComponentType>();
			if (!component.lock()) {
				assert(!"コンポーネントが見つかりません。");
				return;
			}
			component->setup(m_pEntity, m_pInfomation->pPosition);
			m_pComponentList.emplace_back(component);
		}

		template<typename CastType>
		util::WeakPtr<CastType> getComponentCast(Component* component) {
			if (m_pComponentList.empty()) { return util::WeakPtr<CastType>(); }
			for (auto& c : m_pComponentList) {
				if (c.get() == component) { return std::static_pointer_cast<CastType>(c); }
			}
			assert(!"コンポーネントが見つかりません。");
			return util::WeakPtr<CastType>();
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