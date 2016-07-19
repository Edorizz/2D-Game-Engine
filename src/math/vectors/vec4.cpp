#include "vec4.h"

vec4::vec4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}

vec4& vec4::Add(const vec4& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

vec4& vec4::Sub(const vec4& other) {
	x -= other.x;
	y -= other.x;
	z -= other.z;
	w -= other.w;
	return *this;
}

vec4& vec4::Mult(float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
	return *this;
}

vec4& vec4::Div(float scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
	w /= scalar;
	return *this;
}

vec4& operator+(vec4 left, const vec4 &right) {
	return left.Add(right);
}

vec4& operator-(vec4 left, const vec4 &right) {
	return left.Sub(right);
}

vec4& operator*(vec4 vector, float scalar) {
	return vector.Mult(scalar);
}

vec4& operator/(vec4 vector, float scalar) {
	return vector.Div(scalar);
}

std::ostream& operator<<(std::ostream &stream, vec4 vector) {
	return stream << '(' << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ')';
}

vec4& vec4::operator+=(const vec4& other) {
	return Add(other);
}

vec4& vec4::operator-=(const vec4& other) {
	return Sub(other);
}

vec4& vec4::operator*=(float scalar) {
	return Mult(scalar);
}

vec4& vec4::operator/=(float scalar) {
	return Div(scalar);
}