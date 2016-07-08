#pragma once



namespace util {
	struct Vector2;
	class VectorMath
	{
	public:
		VectorMath() {}
		~VectorMath() {}

		static Vector2	normalize(const util::Vector2& vector);
		static double	length(const Vector2& vector);
		static double	dot(const Vector2& fromPos, const Vector2& toPos, const Vector2& posTarget);
		static double	cross(const Vector2& fromPos, const Vector2& toPos, const Vector2& posTarget);

	private:

	};
}