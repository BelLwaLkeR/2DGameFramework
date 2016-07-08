#pragma once

namespace framework {
	class IDrawTask{
	public:
		IDrawTask();
		~IDrawTask();
		virtual void draw()		= 0;

	protected:
		virtual void active();
		virtual void deActive();

	private:

	};
}