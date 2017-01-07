#include "Quaternion.h"

#include <Source/Utility/Type/Vector2.h>


util::Quaternion::Quaternion(float pitch, float yaw, float roll) {
	double cosYaw	= std::cos(yaw * 0.5f);
	double sinYaw	= std::sin(yaw * 0.5f);
	double cosRoll	= std::cos(roll * 0.5f);
	double sinRoll	= std::sin(roll * 0.5f);
	double cosPitch	= std::cos(pitch * 0.5f);
	double sinPitch	= std::sin(pitch * 0.5f);

	t = cosYaw * cosRoll * cosPitch + sinYaw * sinRoll * sinPitch;
	x = cosYaw * sinRoll * cosPitch - sinYaw * cosRoll * sinPitch;
	y = cosYaw * cosRoll * sinPitch + sinYaw * sinRoll * cosPitch;
	z = sinYaw * cosRoll * cosPitch - cosYaw * sinRoll * sinPitch;
}

util::Quaternion::Quaternion(const Vector3& lookFrom, const Vector3& lookTo) {
	Vector3 vector	= lookTo - lookFrom;
	float pitch		= std::atan2f( vector.Y, -vector.Z);
	float yaw		= std::atan2f( vector.Z,  vector.X);
	float roll		= std::atan2f( vector.Y,  vector.X);
	Quaternion( pitch, yaw, roll);
}

util::Quaternion::Quaternion(const Vector2 & lookFrom, const Vector2 & lookTo)
	:axis(Vector3::forward()),
	angle(std::atan2(lookTo.Y - lookFrom.Y, lookTo.X - lookFrom.X)) {
}

util::Quaternion::Quaternion(const util::Vector3& axis, float angleRad) {
	Vector3 normalAxis = axis.normalize();
	this->axis = normalAxis * std::sinf(angleRad / 2);
	t = std::cosf(angleRad/2);
}

util::Quaternion util::Quaternion::identity() {
	return {0, 0, 0, 1};
}

float util::Quaternion::pitch() {
	return std::asinf( -2*(x*z - y*t) );
}

float util::Quaternion::yaw() {
	return std::atan2f(
		2*(x*y + z*t), 
		x*x - y*y - z*z + t*t
	);
}

float util::Quaternion::roll() {
	return std::atan2f(
		2*(y*z + x*t),
		-x*x - y*y + z*z + t*t
	);
}

util::Vector3 util::Quaternion::getPitchYawRoll() {
	return {
		pitch(),
		yaw(),
		roll()
	};
}

void util::Quaternion::rotation(const util::Vector3& axis, float angle) {
	*this + Quaternion(axis, angle);
}

float util::Quaternion::getDistanceAngle(const util::Quaternion & other) {
	return 0.0f;
}

util::Quaternion util::Quaternion::operator+(const Quaternion & other) {
	return{ axis + other.axis, angle + other.angle };
}

util::Quaternion& util::Quaternion::operator+=(const Quaternion & other) {
	return *this;
}

bool util::Quaternion::operator==(const Quaternion& other) const {
	return false;
}

bool util::Quaternion::operator!=(const Quaternion& other) const {
	return false;
}

util::Vector3 util::Quaternion::operator*(const Vector3 & other) {
	Vector3 resoult;

	Vector3 q = angle*std::sinf(angle/2) + std::cosf(angle/2);

	return resoult;

	//http://mathtrain.jp/quaternion
}

util::Vector2 util::Quaternion::operator*(const Vector2 & other) {
	return Vector2();
}


