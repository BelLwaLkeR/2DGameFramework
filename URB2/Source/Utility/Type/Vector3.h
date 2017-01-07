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

		static	Vector3 forward();
		static	Vector3 back();
		static	Vector3 left();
		static	Vector3 right();
		static	Vector3 up();
		static	Vector3 down();
		static	float	dot(const Vector3& value1, const Vector3& value2);
		static	Vector3 cross(const Vector3& value1, const Vector3& value2);


		float lengthSquared()	const;
		float length()			const;

		Vector3 normalize()		const;

		int		getIntX()		const;
		int		getIntY()		const;
		int		getIntZ()		const;

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

	
