#pragma once

namespace framework {
	class IDrawTask{
	public:
		IDrawTask();
		~IDrawTask();

		virtual void update() = 0;

		void active();
		void deActive();
	private:
		bool isActive;

	};
}