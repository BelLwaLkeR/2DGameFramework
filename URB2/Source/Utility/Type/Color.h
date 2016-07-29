#pragma once

/**
* @struct		Color
* @namespace	util
* @brief		�F�p�̍\���́B0����255�̒l�Őݒ�B
* @author		��X ���i
*/


namespace util {
	struct Color{
		//! �ԁB0-255�Ŏw��
		int R;
		//! �΁B0-255�Ŏw��
		int G;
		//! �B0-255�Ŏw��
		int B;
		//! �����x�B0-255�Ŏw��
		int A;

		/**
		* @brief	�Ԃ̒l��float��0����1.0�ŕԂ��B
		*/
		float getRedF()		const;
		/**
		* @brief	�΂̒l��float��0����1.0�ŕԂ��B
		*/
		float getGreenF()	const;
		/**
		* @brief	�̒l��float��0����1.0�ŕԂ��B
		*/
		float getBlueF()	const;
		/**
		* @brief	�����x�̒l��float��0����1.0�ŕԂ��B
		*/
		float getAlphaF()	const;

		/**
		* @brief	�e�F�̏������B
		*/
		void setup(int red, int green, int blue, int alpha = 255);

		/**
		* @brief	�e�F��0����1.0�ŏ������B
		*/
		void setFromFloat(float red, float green, float blue, float alpha = 1.f);
	};
}