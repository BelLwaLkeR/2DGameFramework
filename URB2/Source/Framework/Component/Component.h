#pragma once
#include <Source/Utility/SmartPtr.h>

namespace util {
	struct Vector2;
}

namespace framework {
	class Entity;
	class Component{
	public:
		Component();
		Component(util::WeakPtr<Entity> pEntity, util::WeakPtr<util::Vector2> pPosition);
		~Component();

		void setup(util::WeakPtr<Entity> pEntity, util::WeakPtr<util::Vector2> pPosition);
		virtual void active() {}
		virtual void deactive() {}

	protected:
		util::WeakPtr<Entity>			m_pEntity;
		util::WeakPtr<util::Vector2>	m_pPosition;

		void setEntityPtr(util::WeakPtr<Entity> pEntity);
		void setPositionPtr(util::WeakPtr<util::Vector2> pPosition);

	private:
	};
}