#pragma once

#include <cmath>
#include <Source/Utility/Type/Vector3.h>


namespace util {
	class Vector2;
	class Quaternion {
	public:
		Quaternion():axis(Vector3::forward()), angle(0){}
		Quaternion(float x, float y, float z, float t) :axis(x, y, z), angle(t) {}
		Quaternion(float pitch, float yaw, float roll);
		Quaternion(const Vector3& lookFrom, const Vector3& lookTo);
		Quaternion(const Vector2& lookFrom, const Vector2& lookTo);
		Quaternion(const util::Vector3& axis, float angleRad);

		util::Vector3 axis;
		float angle;

		float& x = axis.X;
		float& y = axis.Y;
		float& z = axis.Z;
		float& t = angle;

		static Quaternion identity();

		float pitch();
		float yaw();
		float roll();
		Vector3 getPitchYawRoll();

		void rotation(const util::Vector3& axis, float angle);
		float getDistanceAngle(const util::Quaternion& other);

		Quaternion operator+(const Quaternion& other);
		Quaternion& operator+=(const Quaternion& other);
		bool operator==(const Quaternion& other) const;
		bool operator!=(const Quaternion& other) const;
		Vector3 operator*(const Vector3& other);
		Vector2 operator*(const Vector2& other);


	private:

	};
}



