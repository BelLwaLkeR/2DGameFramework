#pragma once

/**
* @struct		Color
* @namespace	util
* @brief		色用の構造体。0から255の値で設定。
* @author		大森 健司
*/


namespace util {
	struct Color{
		//! 赤。0-255で指定
		int R;
		//! 緑。0-255で指定
		int G;
		//! 青。0-255で指定
		int B;
		//! 透明度。0-255で指定
		int A;

		/**
		* @brief	赤の値をfloatの0から1.0で返す。
		*/
		float getRedF()		const;
		/**
		* @brief	緑の値をfloatの0から1.0で返す。
		*/
		float getGreenF()	const;
		/**
		* @brief	青の値をfloatの0から1.0で返す。
		*/
		float getBlueF()	const;
		/**
		* @brief	透明度の値をfloatの0から1.0で返す。
		*/
		float getAlphaF()	const;

		/**
		* @brief	各色の初期化。
		*/
		void setup(int red, int green, int blue, int alpha = 255);

		/**
		* @brief	各色を0から1.0で初期化。
		*/
		void setFromFloat(float red, float green, float blue, float alpha = 1.f);
	};
}