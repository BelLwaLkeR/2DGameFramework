#pragma once

#include <DxLib.h>
#include <Source/Utility/FPSManager.h>

namespace framework {
	struct WindowConfig;

	class DxLibApplication
	{
	public:
		DxLibApplication();
		~DxLibApplication();
		void run();
	protected:

		virtual void initialize()	= 0;
		virtual void update()		= 0;
		virtual void draw()			= 0;
		virtual void finalize()		= 0;
		virtual bool isEnd();
		virtual void adjustFPS();
		virtual void setupWindowConfig() = 0;
		void setupWindowConfig(const WindowConfig& windowConfig);

	private:
		void setup();
		void refreshScreen();
		bool isApplicationEnd();
		void teardown();
		void setupWindow(const WindowConfig& windowConfig);
		void setLogOutput();

	};

}