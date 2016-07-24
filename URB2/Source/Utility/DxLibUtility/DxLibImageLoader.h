#pragma once
#include <string>
#include <vector>
#include <DxLib.h>
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>
#include <Source/Utility/Type/Vector2.h>

/**
* @class		DxLibImageLoader
* @namespace	util
* @brief		DxLibの機能を使い、画像データを読み込む関数クラス
* @author		大森 健司
*/

namespace util {
	class DxLibImageLoader{
	public:
		DxLibImageLoader()	{}
		~DxLibImageLoader()	{}

		/**	
		* @brief 横に並んだ複数の画像を指定したサイズ・枚数に分割する。アニメ用
		* @param	[in] (string)	filePath		画像のファイルパス
		* @param	[in] (Vector2)	oneImageSize	一枚当たりの画像サイズ
		* @param	[in] (int)		imageNum		画像何枚あるか
		* @return	(vector<image_t>) ファイルハンドル。-1で読み込みエラー。その他で成功
		*/
		static std::vector<image_t> loadImageDiv(const std::string& filePath, const Vector2& oneImageSize, int imageNum);

	};
}


