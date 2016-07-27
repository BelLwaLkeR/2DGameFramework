#include "ShaderManager.h"
#include <Source/Framework/Device/Renderer/ImageRenderer/Shader/NormalMapShader.h>

void framework::ShaderManager::initialize(){
	setShader<NormalMapShader>();
}
