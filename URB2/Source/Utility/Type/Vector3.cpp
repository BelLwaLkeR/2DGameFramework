#include "Vector3.h"
#include <cassert>
#include <cmath>

util::Vector3::Vector3(float x, float y, float z):X(x), Y(y), Z(y){
}

util::Vector3 util::Vector3::zero(){
	return {0, 0, 0};
}

util::Vector3 util::Vector3::one(){
	return {1, 1, 1};
}

util::Vector3 util::Vector3::forward() {
	return {0, 0, 1};
}

util::Vector3 util::Vector3::back() {
	return {0, 0, -1};
}

util::Vector3 util::Vector3::left() {
	return {-1, 0, 0};
}

util::Vector3 util::Vector3::right() {
	return {1, 0, 0};
}

util::Vector3 util::Vector3::up() {
	return {0, -1, 0};
}

util::Vector3 util::Vector3::down() {
	return {0, 1, 0};
}

float util::Vector3::dot(const Vector3 & value1, const Vector3 & value2) {
	return	value1.X * value2.X +
			value1.Y * value2.Y +
			value1.Z * value2.Z;
}

util::Vector3 util::Vector3::cross(const Vector3 & value1, const Vector3 & value2) {
	return { value1.Y * value2.Z - value1.Z * value2.Y,
			 value1.Z * value2.X - value1.X * value2.Z, 
			 value1.X * value2.Y - value1.Y * value2.X };
}

float util::Vector3::lengthSquared() const{
	return X*X + Y*Y + Z*Z;
}

float util::Vector3::length() const{
	return std::sqrtf(lengthSquared());
}

util::Vector3 util::Vector3::normalize() const{
	return Vector3(X, Y, Z) / length();
}

int util::Vector3::getIntX() const{
	return static_cast<int>(X);
}

int util::Vector3::getIntY() const{
	return static_cast<int>(Y);
}

int util::Vector3::getIntZ() const{
	return static_cast<int>(Z);
}

util::Vector3 & util::Vector3::operator+=(const Vector3 & other){
	X += other.X;
	Y += other.Y;
	Z += other.Z;
	return *this;
}

util::Vector3 & util::Vector3::operator-=(const Vector3 & other){
	X -= other.X;
	Y -= other.Y;
	Z -= other.Z;
	return *this;
}

util::Vector3 & util::Vector3::operator*=(const Vector3 & other){
	X *= other.X;
	Y *= other.Y;
	Z *= other.Z;
	return *this;
}

util::Vector3 & util::Vector3::operator*=(float other){
	X *= other;
	Y *= other;
	Z *= other;
	return *this;
}

util::Vector3 & util::Vector3::operator/=(const Vector3 & other){
	assert(other.X != 0 && other.Y != 0 && other.Z != 0 && "Vector3ÇÃoperator/=Ç≈ÅAÉ[ÉçèúéZÇåüímÇµÇ‹ÇµÇΩÅB");
	X /= other.X;
	Y /= other.Y;
	Z /= other.Z;
	return *this;
}

util::Vector3 & util::Vector3::operator/=(float other){
	assert(other != 0 && "Vector3ÇÃoperator/=Ç≈ÅAÉ[ÉçèúéZÇåüímÇµÇ‹ÇµÇΩÅB");
	X /= other;
	Y /= other;
	Z /= other;
	return *this;
}

util::Vector3 util::Vector3::operator+(const Vector3 & other) const{
	return { X + other.X, Y + other.Y, Z + other.Z };
}

util::Vector3 util::Vector3::operator-(const Vector3 & other) const{
	return { X - other.X, Y - other.Y, Z - other.Z };
}

util::Vector3 util::Vector3::operator*(const Vector3 & other) const{
	return { X * other.X, Y * other.Y, Z * other.Z };
}

util::Vector3 util::Vector3::operator*(float other) const{
	return { X * other, Y * other, Z * other };
}

util::Vector3 util::Vector3::operator/(const Vector3 & other) const{
	assert(other.X != 0 && other.Y != 0 && other.Z != 0 && "Vector3ÇÃoperator/Ç≈ÅAÉ[ÉçèúéZÇåüímÇµÇ‹ÇµÇΩÅB");
	return { X / other.X, Y / other.Y, Z / other.Z };
}

util::Vector3 util::Vector3::operator/(float other) const{
	assert(other != 0 && "Vector3ÇÃoperator/Ç≈ÅAÉ[ÉçèúéZÇåüímÇµÇ‹ÇµÇΩÅB");
	return { X / other, Y / other, Z / other };
}

bool util::Vector3::operator==(const Vector3 & other) const{
	return	X == other.X &&
			Y == other.Y &&
			Z == other.Z;
}

bool util::Vector3::operator!=(const Vector3 & other) const{
	return !(*this == other);
}


