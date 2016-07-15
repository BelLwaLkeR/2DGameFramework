#pragma once
#include <cassert>

namespace util {
	class Math
	{
	public:
		Math()	{}
		~Math()	{}
		
		static int clamp(int value, int max, int min);
		static int loop(int value, int max, int min);
		static const float PI;


		template<typename T>
		static void swap(T* value1, T* value2);
		template<typename T>
		static void swapMinMax(T* min, T* max);
		template<typename T>
		static bool isFall(const T& value, const T& min, const T& max);

	};


	template<typename T>
	inline void Math::swap(T * valueA, T * valueB){
		T tmp = *valueA;
		*valueA = *valueB;
		*valueB = tmp;
	}

	template<typename T>
	inline void Math::swapMinMax(T * min, T * max){
		if (*min <= *max) { return; }
		swap(min, max);
	}
	template<typename T>
	inline bool Math::isFall(const T & value, const T& min, const T& max){
		assert( min <= max && "util::Math::isFallŠÖ”‚Ìmin‚ªmax‚Ì’l‚ð’´‚¦‚Ä‚¢‚Ü‚·BC³‚µ‚Ä‚­‚¾‚³‚¢B");
		return (value >= min && value <= max);
	}
}