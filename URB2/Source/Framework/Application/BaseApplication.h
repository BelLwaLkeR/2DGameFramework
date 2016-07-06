#pragma once

namespace framework {
	class BaseApplication
	{
	public:
		BaseApplication();
		~BaseApplication();

		void initialize();
		void update();
		void draw();
		void finalize();

	protected:

	private:

	};

}