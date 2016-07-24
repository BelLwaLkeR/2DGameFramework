#pragma once
#include <string>

/**
* @struct		Vector2
* @namespace	util
* @brief		二次元用の座標用構造体
* @author		大森 健司
*/


namespace util {
	struct Vector2 {
		float X;
		float Y;

		Vector2(float x = 0.0f, float y = 0.0f);

		static	Vector2	Zero();
		static	Vector2	One();
		static	Vector2	Left();
		static	Vector2	Right();
		static	Vector2	Top();
		static	Vector2	Bottom();

		int		getIntX() const;
		int		getIntY() const;

		Vector2&	operator+=(const Vector2& other);
		Vector2&	operator-=(const Vector2& other);
		Vector2&	operator*=(const Vector2& other);
		Vector2&	operator*=(float other);
		Vector2&	operator/=(const Vector2& other);
		Vector2&	operator/=(float other);
		Vector2		operator+(const Vector2& other)		const;
		Vector2		operator-(const Vector2& other)		const;
		Vector2		operator*(const Vector2& other)		const;
		Vector2		operator*(float other)				const;
		Vector2		operator/(const Vector2& other)		const;
		Vector2		operator/(float other)				const;
		bool		operator==(const Vector2& other)	const;
		bool		operator!=(const Vector2& other)	const;

	};
}