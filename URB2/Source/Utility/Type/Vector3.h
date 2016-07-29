#pragma once

/**
* @struct		Vector3
* @namespace	util
* @brief		三次元次元用の座標用構造体
* @author		大森 健司
*/

namespace util { 
	struct Vector3{
		float X;
		float Y;
		float Z;

		Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

		static	Vector3	zero();
		static	Vector3	one();

		int		getIntX() const;
		int		getIntY() const;
		int		getIntZ() const;

		Vector3&	operator+=(const Vector3& other);
		Vector3&	operator-=(const Vector3& other);
		Vector3&	operator*=(const Vector3& other);
		Vector3&	operator*=(float other);
		Vector3&	operator/=(const Vector3& other);
		Vector3&	operator/=(float other);
		Vector3		operator+(const Vector3& other)		const;
		Vector3		operator-(const Vector3& other)		const;
		Vector3		operator*(const Vector3& other)		const;
		Vector3		operator*(float other)				const;
		Vector3		operator/(const Vector3& other)		const;
		Vector3		operator/(float other)				const;
		bool		operator==(const Vector3& other)	const;
		bool		operator!=(const Vector3& other)	const;
	};
}

	
