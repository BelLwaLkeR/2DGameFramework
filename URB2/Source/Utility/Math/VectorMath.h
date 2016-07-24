#pragma once

/**
* @class		VectorMath
* @namespace	util
* @brief		ベクトル用の計算クラス
* @author		大森 健司
*/




namespace util {
	struct Vector2;
	class VectorMath{
	public:
		VectorMath() {}
		~VectorMath() {}

		static Vector2	normalize(const util::Vector2& vector);
		static double	length(const Vector2& vector);
		static double	length2(const Vector2& vector);
		static double	dot(const Vector2& fromPos, const Vector2& toPos, const Vector2& posTarget);
		static double	cross(const Vector2& fromPos, const Vector2& toPos, const Vector2& posTarget);

	private:

	};
}