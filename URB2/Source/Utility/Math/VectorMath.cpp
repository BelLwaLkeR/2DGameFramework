#include "VectorMath.h"
#include <Source/Utility/Type/Vector2.h>

util::Vector2 util::VectorMath::normalize(const util::Vector2 & vector){
	if (vector == Vector2::Zero()) { return Vector2(); }
	return vector / (float)length(vector);
}

double util::VectorMath::length(const util::Vector2& vector) {
	return sqrt(length2(vector));
}

double util::VectorMath::length2(const Vector2 & vector){
	return pow((double)(vector.X), 2) + pow((double)(vector.Y), 2);
}

double util::VectorMath::dot(const util::Vector2& fromPos, const util::Vector2& toPos, const util::Vector2& posTarget) {
	util::Vector2 unitVec = normalize(toPos - fromPos);
	util::Vector2 targetVec = posTarget - fromPos;
	return (targetVec.X * unitVec.X + targetVec.Y * unitVec.Y);
}

double util::VectorMath::cross(const util::Vector2& fromPos, const util::Vector2& toPos, const util::Vector2& posTarget) {
	util::Vector2 unitVec = normalize(toPos - fromPos);;
	util::Vector2 targetVec = posTarget - fromPos;
	return (unitVec.X * targetVec.Y - targetVec.X * unitVec.Y);
}


