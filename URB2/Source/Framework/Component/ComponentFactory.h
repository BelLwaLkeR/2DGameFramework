#pragma once
#include <unordered_map>
#include <string>
#include <Source/Utility/SmartPtr.h>

namespace component {
#include <Source/Framework/Component/Component.h>
	class tmpComponent: public framework::Component{
	public:
		tmpComponent() {}
		~tmpComponent() {}
	};
}

namespace framework {
	class Component;
	//コンポーネント作成用インターフェース
	class IComponentMaker{
	public:
		virtual Component* create() = 0;
	};
	//コンポーネント作成用テンプレートクラス
	template<typename ComponentType>
	class ComponentMaker: public IComponentMaker{
	public:
		ComponentType* create() override{
			return new ComponentType();
		}
	};

	#define MAKE_COMPONENT_TYPE(namespace_less_type) util::makeShared<component::namespace_less_type>()
	#define CREATE_BLUEPRINT_ARGS(namespace_less_type) #namespace_less_type, MAKE_COMPONENT_TYPE(namespace_less_type)
	
	class Component;
	class ComponentFactory
	{
	public:
		ComponentFactory();
		~ComponentFactory();

		void setupBlueprintList();
		void addBluePrint(const std::string& componentName, util::SharedPtr<IComponentMaker> componentPointer);
		void addBluePrint(const std::string& componentName, Component* componentPointer);
		util::SharedPtr<Component> createComponent(const std::string& componentName);
		void clearBlueprintList();

	private:
		std::unordered_map<std::string, util::SharedPtr<IComponentMaker>> m_pComponentBlueprintList;


	};
}