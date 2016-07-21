#pragma once
#include <unordered_map>
#include <string>
#include <cassert>
#include <Source/Framework/Component/ComponentCreator.h>
#include <Source/Framework/Component/Component.h>
#include <Source/Framework/Entity/EntityInfomation.h>
#include <Source/Utility/Singleton.h>
#include <Source/Utility/SmartPtr.h>
#include <Source/Utility/StringEditor.h>

#define SGLT_COMPONENT_FACTORY framework::ComponentFactory::getInstance()

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
		util::SharedPtr<Component> createComponent(const std::string& componentName);

		template<typename ComponentType>
		util::SharedPtr<Component> createComponent() {
			return createComponent(util::StringEditor::getClassName<ComponentType>());
		}

	private:
		std::unordered_map<std::string, util::SharedPtr<IComponentCreator>> m_pComponentBlueprintList;

	};

}