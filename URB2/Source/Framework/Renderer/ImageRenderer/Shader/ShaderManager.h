
#pragma once

#include <map>
#include <string>
#include <cassert>
#include <Source/Utility/SmartPtr.h>
#include <Source/Utility/Singleton.h>
#include <Source/Utility/StringEditor.h>
#include <Source/Framework/Renderer/ImageRenderer/Shader/IPixelShader.h>

/**
* @class		Shadermanager
* @inheritance	Singleton<ShaderManager>
* @namespace	framework
* @brief		�V�F�[�_�N���X���܂Ƃ߂�N���X
* @author		��X ���i
*/

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
		template<typename ShaderType>
		void deleteShader();

	private:
		std::map<std::string, util::SharedPtr<IPixelShader>> m_pShaderMap;
	};

	template<typename ShaderType>
	inline void ShaderManager::setShader(){
		assert(m_pShaderMap.find(util::StringEditor::getClassName<ShaderType>()) == m_pShaderMap.end() && "���ɑ��݂���V�F�[�_��ǂݍ������Ƃ��܂����B");
		m_pShaderMap[util::StringEditor::getClassName<ShaderType>()] = util::makeShared<ShaderType>();
	}

	template<typename ShaderType>
	inline void ShaderManager::attachShader(util::SharedPtr<util::ImageData>* image){
		assert(m_pShaderMap.find(util::StringEditor::getClassName<ShaderType>()) != m_pShaderMap.end() && "attachShader�ŗ��p���悤�Ƃ����V�F�[�_��set����Ă��܂���ł����B");
		m_pShaderMap[util::StringEditor::getClassName<ShaderType>()]->attachShader(image);

	}
	template<typename ShaderType>
	inline void ShaderManager::deleteShader(){
		assert(m_pShaderMap.find(util::StringEditor::getClassName<ShaderType>()) != m_pShaderMap.end() && "deleteShader�ō폜���悤�Ƃ����V�F�[�_��set����Ă��܂���ł����B");
		m_pShaderMap[util::StringEditor::getClassName<ShaderType>()]->deleteShader();
	}
}
