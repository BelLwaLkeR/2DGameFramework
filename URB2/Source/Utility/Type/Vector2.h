#pragma once
#include <string>

namespace util {
	struct Vector2 {
		float X;
		float Y;

		Vector2(float x = 0.0f, float y = 0.0f);

		static	Vector2	zero();
		static	Vector2	one();

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