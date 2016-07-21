#include "Vector2.h"

 util::Vector2::Vector2(float x, float y) : X(x), Y(y) {
	
 }

 util::Vector2 util::Vector2::Zero() {
	return {0, 0};
}

util::Vector2 util::Vector2::One() {
	return {1, 1};
}

util::Vector2 util::Vector2::Left(){
	return {-1, 0};
}

util::Vector2 util::Vector2::Right(){
	return {1, 0};
}

util::Vector2 util::Vector2::Top(){
	return {0, -1};
}

util::Vector2 util::Vector2::Bottom(){
	return {0, 1};
}

int	util::Vector2::getIntX() const{
	return (int)X;
}

int	util::Vector2::getIntY() const{
	return (int)Y;
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
	X = (other.X == 0) ? 0 : X / other.X;
	Y = (other.Y == 0) ? 0 : Y / other.Y;
	return *this;
}

util::Vector2& util::Vector2::operator/=(float other) {
	X = (other == 0) ? 0 : X / other;
	Y = (other == 0) ? 0 : Y / other;
	return *this;
}

util::Vector2 util::Vector2::operator+(const util::Vector2& other) const{
	util::Vector2 tmp(1.f, 1.f);
	tmp.X = X + other.X;
	tmp.Y = Y + other.Y;
	return tmp;
}


util::Vector2 util::Vector2::operator-(const util::Vector2& other) const{
	util::Vector2 tmp(0, 0);
	tmp.X = X - other.X;
	tmp.Y = Y - other.Y;
	return tmp;
}


util::Vector2 util::Vector2::operator*(const util::Vector2& other) const {
	util::Vector2 tmp(0, 0);
	tmp.X = X * other.X;
	tmp.Y = Y * other.Y;
	return tmp;
}

util::Vector2 util::Vector2::operator*(float other) const {
	util::Vector2 tmp(0, 0);
	tmp.X = X * other;
	tmp.Y = Y * other;
	return tmp;
}


util::Vector2 util::Vector2::operator/(const util::Vector2& other) const {
	util::Vector2 tmp(0, 0);
	tmp.X = X / other.X;
	tmp.Y = Y / other.Y;
	return tmp;
}

util::Vector2 util::Vector2::operator/(float other) const {
	util::Vector2 tmp(0, 0);
	tmp.X = X / other;
	tmp.Y = Y / other;
	return tmp;
}

bool util::Vector2::operator==(const util::Vector2& other) const{
	return (X == other.X
		&& Y == other.Y);
}


bool util::Vector2::operator!=(const util::Vector2& other) const{
	return !(*this == other);
}



