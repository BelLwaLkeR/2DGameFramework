#pragma once

#include <Source/Utility/SmartPtr.h>
#include <Source/Framework/Component/Component.h>
#include <Source/Framework/Entity/EntityInfomation.h>

namespace framework {
	class IComponentCreator {
	public:
		IComponentCreator()	{}
		~IComponentCreator(){}
		virtual util::SharedPtr<Component> create(util::WeakPtr<EntityInfomation> entityInfo) = 0;
	};

	template<typename ComponentType>
	class ComponentCreator: public IComponentCreator{
	public:
		ComponentCreator()	{}
		~ComponentCreator()	{}
		util::SharedPtr<Component> create(util::WeakPtr<EntityInfomation> entityInfo) override{
			util::SharedPtr<Component> componentPointer = util::makeShared<ComponentType>();
			componentPointer->setEntityInfomation(entityInfo);
			return componentPointer;
		}
	};


}
