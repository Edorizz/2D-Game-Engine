#pragma once

#include "../vectors/vec3.h"

class mat4 {
private:
	float data[4][4]; // data[col][row]
public:
	static mat4 Void();
	static mat4 Identity();
	static mat4 Translate(const vec3 &vector);
	static mat4 Rotate(float angle, const vec3 &vector);

	friend mat4 operator*(mat4 &left, mat4 &right);
	friend vec3 operator*(mat4 &matrix, const vec3 &right);

	float* GetData() { return *data; }
};