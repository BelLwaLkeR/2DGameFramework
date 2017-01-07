#pragma once

#include <Source/Framework/Application/DxLibApplication.h>
#include <Source/Framework/Device/Input/InputManager.h>
#include <Source/Framework/Scene/SceneManager.h>

/**
* @class		GameApplication
* @inheritance	DxLibApplication
* @namespace	framework
* @brief		ゲームループの最低限の実装用クラス。
* @author		大森 健司
*/


namespace framework {
	class GameApplication: public DxLibApplication {
	public:
		GameApplication();
		~GameApplication();
		void run();

	private:
		InputManager input;
		SceneManager sceneManager;

		void initialize()	override;
		void update()		override;
		void draw()			override;
		void finalize()		override;
		bool isEnd()		override;
		void setupWindowConfig() override;
	};
}