#pragma once

/**
* @class		VectorMath
* @namespace	util
* @brief		ベクトル用の計算クラス
* @author		大森 健司
*/




namespace util {
	struct Vector2;
	struct Vector3;
	class VectorMath{
	public:
		VectorMath() {}
		~VectorMath() {}

		static Vector2	normalize(const util::Vector2& vector);
		static double	length(const Vector2& vector);
		static double	length2(const Vector2& vector);
		static double	dot(const Vector2& fromPos, const Vector2& toPos, const Vector2& posTarget);
		static double	cross(const Vector2& fromPos, const Vector2& toPos, const Vector2& posTarget);

		float getAngleFrom2Vector(const util::Vector2& vector1, const util::Vector2& vector2);
		float getAngleFrom2Vector(const util::Vector3& vector1, const util::Vector3& vector2);


	private:

	};
}