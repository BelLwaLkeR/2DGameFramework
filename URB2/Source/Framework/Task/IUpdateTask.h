#pragma once

namespace framework {
	class IUpdateTask {
	public:
		IUpdateTask();
		~IUpdateTask();
		virtual void update()	= 0;

	protected:
		virtual void active()	= 0;
		virtual void deActive()	= 0;

	private:

	};
}