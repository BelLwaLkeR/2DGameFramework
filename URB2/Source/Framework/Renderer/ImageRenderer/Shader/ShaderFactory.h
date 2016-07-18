#pragma once
#include <map>
#include <string>
#include <Source/Utility/Singleton.h>
#include <Source/Utility/SmartPtr.h>
#include <Source/Utility/StringEditor.h>

#define SGLT_SHADERFACTORY framework;;ShaderFactory::getInstance()

namespace framework {
	class PixelShader;
	class ShaderFactory: public util::Singleton<ShaderFactory>{
	public:
		ShaderFactory();
		~ShaderFactory();
		void setupShaderMap();
		template<typename ShaderName>
		util::WeakPtr<PixelShader> getPixelShader();
		util::WeakPtr<PixelShader> getPixelShader(const std::string& ShaderTypeName);

	private:
		std::map<std::string, util::SharedPtr<PixelShader>> m_pPixelShaderList;

	};

	template<typename ShaderName>
	inline util::WeakPtr<PixelShader> ShaderFactory::getPixelShader(){
		std::string&& typeName = util::StringEditor::getClassName<ShaderName>();
		return getPixelShader(typeName);
	}
}