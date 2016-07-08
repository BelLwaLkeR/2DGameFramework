#include "Hash.h"

util::Hash::Hash():m_Hash(0){
}

util::Hash::Hash(const std::string & str){
	m_Hash = toHash(str);
}

util::Hash::Hash(const char * c){
	m_Hash = toHash(c);
}

std::size_t util::Hash::toHash(const std::string & str) const{
	return std::hash<std::string>()(str);
}

std::size_t util::Hash::toHash(const char * c) const{
	return std::hash<std::string>()(std::string(c));
}

util::Hash& util::Hash::operator=(const Hash & hash){
	this->m_Hash = hash.m_Hash;
	return *this;
}

util::Hash& util::Hash::operator=(const std::string & str){
	this->m_Hash = toHash(str);
	return *this;
}

util::Hash& util::Hash::operator=(const char * c){
	this->m_Hash = toHash(c);
	return *this;
}

bool util::Hash::operator==(const Hash & hash) const{
	return (this->m_Hash == hash.m_Hash);
}

bool util::Hash::operator==(const std::string & str) const{
	return (this->m_Hash == toHash(str));
}

bool util::Hash::operator==(const char * c) const{
	return (this->m_Hash == toHash(c));
}

bool util::Hash::operator!=(const Hash & hash) const{
	return (this->m_Hash != hash.m_Hash);
}

bool util::Hash::operator!=(const std::string & str) const{
	return (this->m_Hash != toHash(str));
}

bool util::Hash::operator!=(const char * c) const{
	return (this->m_Hash != toHash(c));
}

std::size_t util::Hash::operator()(const Hash & hash) const{
	return hash.m_Hash;
}
