#pragma once

#include <map>
#include <string>
#include <cassert>
#include <Source/Utility/SmartPtr.h>
#include <Source/Utility/Singleton.h>
#include <Source/Utility/StringEditor.h>
#include <Source/Framework/Renderer/ImageRenderer/Shader/IPixelShader.h>

#define SGLT_SHADER_MANAGER	framework::ShaderManager::getInstance()

namespace framework {
	class ShaderManager: public util::Singleton<ShaderManager>{
	public:
		ShaderManager() {}
		~ShaderManager(){}

		void initialize() override;
		template<typename ShaderType>
		void setShader();
		template<typename ShaderType>
		void attachShader(util::SharedPtr<util::ImageData>* image);

	private:
		std::map<std::string, util::SharedPtr<IPixelShader>> m_pShaderMap;
	};

	template<typename ShaderType>
	inline void ShaderManager::setShader(){
		assert(m_pShaderMap.find(util::StringEditor::getClassName<ShaderType>()) == m_pShaderMap.end() && "既に存在するシェーダを読み込もうとしました。");
		m_pShaderMap[util::StringEditor::getClassName<ShaderType>()] = util::makeShared<ShaderType>();
	}

	template<typename ShaderType>
	inline void ShaderManager::attachShader(util::SharedPtr<util::ImageData>* image){
		assert(m_pShaderMap.find(util::StringEditor::getClassName<ShaderType>()) != m_pShaderMap.end() && "利用しようとしたシェーダがsetされていませんでした。");
		m_pShaderMap[util::StringEditor::getClassName<ShaderType>()]->attachShader(image);

	}
}
