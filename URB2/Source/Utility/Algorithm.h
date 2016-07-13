#pragma once

#include <algorithm>
#include <vector>
#include <list>

namespace util {
	class Algorithm
	{
	public:
		Algorithm();
		~Algorithm();


	private:


	//テンプレート関数
	public:
		template<typename container, typename T>
		static typename container::const_iterator find(container vector, T value) {
			auto itr = std::find(vector.begin(), vector.end(), value);
			if (itr == vector.end()) { return vector.end(); }
			return itr;
		}


	};
}


