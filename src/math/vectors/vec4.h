#pragma once

#include <ostream>

class vec4 {
public:
	float x, y, z, w;
public:
	vec4(float x, float y, float z, float w);

	vec4& Add(const vec4& other);
	vec4& Sub(const vec4& other);
	vec4& Mult(float scalar);
	vec4& Div(float scalar);

	friend vec4& operator+(vec4 left, const vec4 &right);
	friend vec4& operator-(vec4 left, const vec4 &right);
	friend vec4& operator*(vec4 vector, float scalar);
	friend vec4& operator/(vec4 vector, float scalar);
	friend std::ostream& operator<<(std::ostream& stream, vec4 vector);

	vec4& operator+=(const vec4& other);
	vec4& operator-=(const vec4& other);
	vec4& operator*=(float scalar);
	vec4& operator/=(float scalar);
};