#pragma once

#include <Source/Utility/SmartPtr.h>
#include <Source/Framework/Component/Component.h>
#include <Source/Framework/Entity/EntityInfomation.h>

namespace framework {
	class IComponentCreator {
	public:
		IComponentCreator()	{}
		~IComponentCreator(){}
		virtual util::SharedPtr<Component> create() = 0;
	};

	template<typename ComponentType>
	class ComponentCreator: public IComponentCreator{
	public:
		ComponentCreator()	{}
		~ComponentCreator()	{}
		util::SharedPtr<Component> create() override{
			std::string componentName = util::StringEditor::getClassName<ComponentType>();
			return std::static_pointer_cast<Component>(util::makeShared<ComponentType>());
		}
	};


}
