#pragma once
#include <Source/Utility/Type/ImageData.h>
#include <Source/Utility/SmartPtr.h>

/**
* @class		IPixelShader
* @namespace	framework
* @brief		�V�F�[�_�C���^�[�t�F�[�X
* @author		��X ���i
*/

namespace framework {
	class IPixelShader{
	public:
		IPixelShader();
		IPixelShader(util::WeakPtr<util::Vector2> pPosition);
		~IPixelShader();
		void setPixelShader(util::WeakPtr<util::Vector2> pPosition);
		virtual void attachShader(util::SharedPtr<util::ImageData>* targetImage) = 0;
		virtual void deleteShader() = 0;

	private:
		util::WeakPtr<util::Vector2> m_pPosition;
	};
}





