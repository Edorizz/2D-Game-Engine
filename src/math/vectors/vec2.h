#pragma once

#include <ostream>

class vec2 {
private:
	float x, y;
public:
	vec2(float x, float y);

	vec2& Add(const vec2& other);
	vec2& Sub(const vec2& other);
	vec2& Mult(float scalar);
	vec2& Div(float scalar);

	friend vec2& operator+(vec2 left, const vec2 &right);
	friend vec2& operator-(vec2 left, const vec2 &right);
	friend vec2& operator*(vec2 vector, float scalar);
	friend vec2& operator/(vec2 vector, float scalar);
	friend std::ostream& operator<<(std::ostream& stream, vec2 vector);

	vec2& operator+=(const vec2& other);
	vec2& operator-=(const vec2& other);
	vec2& operator*=(float scalar);
	vec2& operator/=(float scalar);
};