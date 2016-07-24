#pragma once

#include <Source/Utility/SmartPtr.h>
#include <Source/Framework/Component/Component.h>
#include <Source/Framework/Entity/EntityInfomation.h>

/**
* @class		IComponentCreator
* @namespace	framework
* @brief		�R���|�[�l���g�����N���X�̃C���^�[�t�F�[�X
* @author		��X ���i
*/



/**
* @class		ComponentCreator
* @inheritance	IComponentCreator
* @namespace	framework
* @brief		�w�肳�ꂽ�R���|�[�l���g�𐶐�����
* @author		��X ���i
*/


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
