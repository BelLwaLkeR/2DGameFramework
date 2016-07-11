#pragma once
#include <unordered_map>
#include <string>
#include <cassert>
#include <Source/Framework/Component/ComponentCreator.h>
#include <Source/Framework/Component/Component.h>
#include <Source/Framework/Entity/EntityInfomation.h>
#include <Source/Utility/Singleton.h>
#include <Source/Utility/SmartPtr.h>

namespace component {
	class tmpComponent: public framework::Component{
	public:
		tmpComponent() {}
		~tmpComponent() {}
	};
}

#define SGLT_COMPONENTFACTORY framework::ComponentFactory::getInstance()

namespace framework {
	#define CREATE_COMPONENT_TYPE(namespace_less_type) util::makeShared<ComponentCreator<namespace_less_type>>()
	#define CREATE_BLUEPRINT_ARGS(namespace_less_type) #namespace_less_type, CREATE_COMPONENT_TYPE(namespace_less_type)
	class ComponentFactory: public util::Singleton<ComponentFactory>{
	public:
		ComponentFactory();
		~ComponentFactory();

		void setupBlueprintList();
		void addBluePrint(const std::string& componentName, util::SharedPtr<IComponentCreator> componentPointer);
		void clearBlueprintList();
		util::SharedPtr<Component> createComponent(const std::string& componentName, util::WeakPtr<EntityInfomation> entityInfomation) {
			assert(m_pComponentBlueprintList.find(componentName) != m_pComponentBlueprintList.end() && "生成するコンポーネントがComponentFactoryのBlueprintに登録されていません。");
			return m_pComponentBlueprintList[componentName]->create(entityInfomation);
		}

	private:
		std::unordered_map<std::string, util::SharedPtr<IComponentCreator>> m_pComponentBlueprintList;

	};
}