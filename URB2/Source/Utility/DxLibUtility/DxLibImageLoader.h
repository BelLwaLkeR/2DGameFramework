#pragma once
#include <string>
#include <vector>
#include <DxLib.h>
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>
#include <Source/Utility/Type/Vector2.h>

/**
* @class		DxLibImageLoader
* @namespace	util
* @brief		DxLib�̋@�\���g���A�摜�f�[�^��ǂݍ��ފ֐��N���X
* @author		��X ���i
*/

namespace util {
	class DxLibImageLoader{
	public:
		DxLibImageLoader()	{}
		~DxLibImageLoader()	{}

		/**	
		* @brief ���ɕ��񂾕����̉摜���w�肵���T�C�Y�E�����ɕ�������B�A�j���p
		* @param	[in] (string)	filePath		�摜�̃t�@�C���p�X
		* @param	[in] (Vector2)	oneImageSize	�ꖇ������̉摜�T�C�Y
		* @param	[in] (int)		imageNum		�摜�������邩
		* @return	(vector<image_t>) �t�@�C���n���h���B-1�œǂݍ��݃G���[�B���̑��Ő���
		*/
		static std::vector<image_t> loadImageDiv(const std::string& filePath, const Vector2& oneImageSize, int imageNum);

	};
}


