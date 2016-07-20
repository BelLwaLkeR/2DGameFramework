#include "ShaderManager.h"
#include <Source/Framework/Renderer/ImageRenderer/Shader/NormalMapShader.h>

void framework::ShaderManager::initialize(){
	setShader<NormalMapShader>();
}
