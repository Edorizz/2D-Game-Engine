#pragma once

#include <ostream>

class vec3 {
public:
	float x, y, z;
public:
	vec3(float x, float y, float z);

	vec3& Add(const vec3& other);
	vec3& Sub(const vec3& other);
	vec3& Mult(float scalar);
	vec3& Div(float scalar);

	friend vec3& operator+(vec3 left, const vec3 &right);
	friend vec3& operator-(vec3 left, const vec3 &right);
	friend vec3& operator*(vec3 vector, float scalar);
	friend vec3& operator/(vec3 vector, float scalar);
	friend std::ostream& operator<<(std::ostream& stream, vec3 vector);

	vec3& operator+=(const vec3& other);
	vec3& operator-=(const vec3& other);
	vec3& operator*=(float scalar);
	vec3& operator/=(float scalar);
};