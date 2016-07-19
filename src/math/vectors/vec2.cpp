#include "vec2.h"

vec2::vec2(float _x, float _y) : x(_x), y(_y) {}

vec2& vec2::Add(const vec2& other) {
	x += other.x;
	y += other.y;
	return *this;
}

vec2& vec2::Sub(const vec2& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

vec2& vec2::Mult(float scalar) {
	x *= scalar;
	y *= scalar;
	return *this;
}

vec2& vec2::Div(float scalar) {
	x /= scalar;
	y /= scalar;
	return *this;
}

vec2& operator+(vec2 left, const vec2 &right) {
	return left.Add(right);
}

vec2& operator-(vec2 left, const vec2 &right) {
	return left.Sub(right);
}

vec2& operator*(vec2 vector, float scalar) {
	return vector.Mult(scalar);
}

vec2& operator/(vec2 vector, float scalar) {
	return vector.Div(scalar);
}

std::ostream& operator<<(std::ostream &stream, vec2 vector) {
	return stream << '(' << vector.x << ", " << vector.y << ')';
}

vec2& vec2::operator+=(const vec2& other) {
	return Add(other);
}

vec2& vec2::operator-=(const vec2& other) {
	return Sub(other);
}

vec2& vec2::operator*=(float scalar) {
	return Mult(scalar);
}

vec2& vec2::operator/=(float scalar) {
	return Div(scalar);
}