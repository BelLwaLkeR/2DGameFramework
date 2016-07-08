#pragma once

#include <algorithm>
#include <vector>

namespace util {
	class Algorithm
	{
	public:
		Algorithm() {}
		~Algorithm() {}

		template<typename T>
		static std::vector<T>::iterator Find(const std::vector<T>* vector, const T* value) const;

	private:

	};


	template<typename T>
	inline static std::vector<T>::iterator Algorithm::Find(const std::vector<T>* vector, const T * value) const
	{
		auto itr = std::find(vector.begin(), vector.end(), value);
		if (itr == vector.end()) { return -1; }
		return itr;
	}
}


