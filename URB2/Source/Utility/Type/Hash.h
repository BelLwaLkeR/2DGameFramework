#pragma once
#include <string>

namespace util {
	struct Hash{
		std::size_t m_Hash;

		Hash();
		Hash(const std::string& str);
		Hash(const char* c);
		std::size_t toHash(const std::string& str) const;
		std::size_t toHash(const char* c) const;
		Hash& operator=(const Hash& hash);
		Hash& operator=(const std::string& str);
		Hash& operator=(const char* c);
		bool operator==(const Hash& hash) const;
		bool operator==(const std::string& str) const;
		bool operator==(const char* c) const;
		bool operator!=(const Hash& hash) const;
		bool operator!=(const std::string& str) const;
		bool operator!=(const char* c) const;
		std::size_t operator()(const Hash& hash) const;


	};
}