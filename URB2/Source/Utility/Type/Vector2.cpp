#include "Vector2.h"
#include <cassert>

 util::Vector2::Vector2(float x, float y) : X(x), Y(y) {
	
 }

 util::Vector2 util::Vector2::zero() {
	return {0, 0};
}

util::Vector2 util::Vector2::one() {
	return {1, 1};
}

float util::Vector2::dot(const Vector2 & value1, const Vector2 & value2) {
	return	value1.X * value2.X + 
			value1.Y * value2.Y;
}

float util::Vector2::cross(const Vector2 & value1, const Vector2 & value2) {
	return value1.X * value2.Y - value1.Y * value2.X;
}

int	util::Vector2::getIntX() const{
	return static_cast<int>(X);
}

int	util::Vector2::getIntY() const{
	return static_cast<int>(Y);
}

util::Vector2& util::Vector2::operator+=(const util::Vector2& other) {
	X += other.X;
	Y += other.Y;
	return *this;
}

util::Vector2& util::Vector2::operator-=(const util::Vector2& other) {
	X -= other.X;
	Y -= other.Y;
	return *this;
}


util::Vector2& util::Vector2::operator*=(const util::Vector2& other) {
	X *= other.X;
	Y *= other.Y;
	return *this;
}

util::Vector2& util::Vector2::operator*=(float other) {
	X *= other;
	Y *= other;
	return *this;
}


util::Vector2& util::Vector2::operator/=(const util::Vector2& other) {
	assert(other.X != 0 && other.Y != 0 && "Vector2‚Ìoperator/=‚ÅAƒ[ƒœZ‚ğŒŸ’m‚µ‚Ü‚µ‚½B");
	X /= other.X;
	Y /= other.Y;
	return *this;
}

util::Vector2& util::Vector2::operator/=(float other) {
	assert(other!= 0 && "Vector2‚Ìoperator/=‚ÅAƒ[ƒœZ‚ğŒŸ’m‚µ‚Ü‚µ‚½B");
	X /= other;
	Y /= other;
	return *this;
}

util::Vector2 util::Vector2::operator+(const util::Vector2& other) const{
	return Vector2(X + other.X, Y + other.Y);
}


util::Vector2 util::Vector2::operator-(const util::Vector2& other) const{
	return Vector2(X - other.X, Y - other.Y);
}


util::Vector2 util::Vector2::operator*(const util::Vector2& other) const {
	return Vector2(X * other.X, Y * other.Y);
}

util::Vector2 util::Vector2::operator*(float other) const {
	return Vector2(X * other, Y * other);
}


util::Vector2 util::Vector2::operator/(const util::Vector2& other) const {
	assert(other.X != 0 && other.Y != 0 && "Vector2‚Ìoperator/‚ÅAƒ[ƒœZ‚ğŒŸ’m‚µ‚Ü‚µ‚½B");
	return Vector2(X / other.X, Y / other.Y);
}

util::Vector2 util::Vector2::operator/(float other) const {
	assert(other != 0 && "Vector2‚Ìoperator/=‚ÅAƒ[ƒœZ‚ğŒŸ’m‚µ‚Ü‚µ‚½B");
	return Vector2(X / other, Y / other);
}

bool util::Vector2::operator==(const util::Vector2& other) const{
	return (X == other.X
		&& Y == other.Y);
}

bool util::Vector2::operator!=(const util::Vector2& other) const{
	return !(*this == other);
}



