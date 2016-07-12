#pragma once
#include <unordered_map>
#include <Source/Utility/SmartPtr.h>

namespace framework {
	class SceneManager{

	public:
		SceneManager();
		SceneManager(const std::string& firstSceneName);
		~SceneManager();

		void load(const std::string& sceneName);
		void start();
		void update();
		void draw();

	private:
		
		void changeScene(const std::string& nextSceneName);
	};
}