#pragma once

#include <DxLib.h>
#include <Source/Utility/FPSManager.h>

/**
* @class		DxLibApplication
* @namespace	framework
* @brief		DxLibを用いたメインループの原型。
* @author		大森 健司
*/


namespace framework {
	struct WindowConfig;

	class DxLibApplication
	{
	public:
		DxLibApplication();
		~DxLibApplication();
	protected:

		virtual void initialize()			= 0;
		virtual void update()				= 0;
		virtual void draw()					= 0;
		virtual void finalize()				= 0;
		virtual void setupWindowConfig()	= 0;
		virtual bool isEnd();
		virtual void adjustFPS();
		void setupWindowConfig(const WindowConfig& windowConfig);
		void run();

	private:

		void setup();
		bool isApplicationEnd();
		void teardown();
		void setupWindow(const WindowConfig& windowConfig);
		void setLogOutput();
		void setupGraphicConfig();
	};

}