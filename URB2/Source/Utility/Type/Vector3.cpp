#include "Vector3.h"
#include <cassert>

util::Vector3::Vector3(float x, float y, float z):X(x), Y(y), Z(y){
}

util::Vector3 util::Vector3::zero(){
	return Vector3();
}

util::Vector3 util::Vector3::one(){
	return Vector3(1, 1, 1);
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
	assert(other.X != 0 && other.Y != 0 && other.Z != 0 && "Vector3‚Ìoperator/=‚ÅAƒ[ƒœZ‚ğŒŸ’m‚µ‚Ü‚µ‚½B");
	X /= other.X;
	Y /= other.Y;
	Z /= other.Z;
	return *this;
}

util::Vector3 & util::Vector3::operator/=(float other){
	assert(other != 0 && "Vector3‚Ìoperator/=‚ÅAƒ[ƒœZ‚ğŒŸ’m‚µ‚Ü‚µ‚½B");
	X /= other;
	Y /= other;
	Z /= other;
	return *this;
}

util::Vector3 util::Vector3::operator+(const Vector3 & other) const{
	return Vector3(X + other.X, Y + other.Y, Z + other.Z);
}

util::Vector3 util::Vector3::operator-(const Vector3 & other) const{
	return Vector3(X - other.X, Y - other.Y, Z - other.Z);
}

util::Vector3 util::Vector3::operator*(const Vector3 & other) const{
	return Vector3(X * other.X, Y * other.Y, Z * other.Z);
}

util::Vector3 util::Vector3::operator*(float other) const{
	return Vector3(X * other, Y * other, Z * other);
}

util::Vector3 util::Vector3::operator/(const Vector3 & other) const{
	assert(other.X != 0 && other.Y != 0 && other.Z != 0 && "Vector3‚Ìoperator/‚ÅAƒ[ƒœZ‚ğŒŸ’m‚µ‚Ü‚µ‚½B");
	return Vector3(X / other.X, Y / other.Y, Z / other.Z);
}

util::Vector3 util::Vector3::operator/(float other) const{
	assert(other != 0 && "Vector3‚Ìoperator/‚ÅAƒ[ƒœZ‚ğŒŸ’m‚µ‚Ü‚µ‚½B");
	return Vector3(X / other, Y / other, Z / other);
}

bool util::Vector3::operator==(const Vector3 & other) const{
	return	X == other.X &&
			Y == other.Y &&
			Z == other.Z;
}

bool util::Vector3::operator!=(const Vector3 & other) const{
	return !(*this == other);
}


