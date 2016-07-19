#include "vec3.h"

vec3::vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

vec3& vec3::Add(const vec3& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

vec3& vec3::Sub(const vec3& other) {
	x -= other.x;
	y -= other.x;
	z -= other.z;
	return *this;
}

vec3& vec3::Mult(float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

vec3& vec3::Div(float scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}

vec3& operator+(vec3 left, const vec3 &right) {
	return left.Add(right);
}

vec3& operator-(vec3 left, const vec3 &right) {
	return left.Sub(right);
}

vec3& operator*(vec3 vector, float scalar) {
	return vector.Mult(scalar);
}

vec3& operator/(vec3 vector, float scalar) {
	return vector.Div(scalar);
}

std::ostream& operator<<(std::ostream &stream, vec3 vector) {
	return stream << '(' << vector.x << ", " << vector.y << ", " << vector.z << ')';
}

vec3& vec3::operator+=(const vec3& other) {
	return Add(other);
}

vec3& vec3::operator-=(const vec3& other) {
	return Sub(other);
}

vec3& vec3::operator*=(float scalar) {
	return Mult(scalar);
}

vec3& vec3::operator/=(float scalar) {
	return Div(scalar);
}