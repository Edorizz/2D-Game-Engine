#include "mat4.h"

//	| 0 0 0 0 |
//	| 0 0 0 0 |
//	| 0 0 0 0 |
//	| 0 0 0 0 |
mat4 mat4::Void() {
	mat4 mat;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			mat.data[y][x] = 0.0f;
		}
	}
	return mat;
}

/*	| 1 0 0 0 |
	| 0 1 0 0 |
	| 0 0 1 0 |
	| 0 0 0 1 |	*/
mat4 mat4::Identity() {
	mat4 mat = mat4::Void();

	mat.data[0][0] = 1.0f;
	mat.data[1][1] = 1.0f;
	mat.data[2][2] = 1.0f;
	mat.data[3][3] = 1.0f;

	return mat;
}


/*	| 1 0 0 x |
	| 0 1 0 y |
	| 0 0 1 z |
	| 0 0 0 1 |	*/
mat4 mat4::Translate(const vec3 &vector) {
	mat4 mat = mat4::Identity();

	mat.data[3][0] = vector.x;
	mat.data[3][1] = vector.y;
	mat.data[3][2] = vector.z;

	return mat;
}

//TODO: Normalize the rotation vector before using it
/*	| x^2(1-c) + c   xy(1-c) - zs   xz(1-c) + ys   0 |
	| xy(1-c) + zs   y^2(1-c) + c   yz(1-c) - xs   0 |
	| xz(1-c) - ys   yz(1-c) + xs   z^2(1-c) + c   0 |
	|      0              0             0          1 |	*/
mat4 mat4::Rotate(float angle, const vec3 &vector) {
	//! This can be replaced by "mat.data[3][3] = 1.0f"
	mat4 mat = mat4::Void();
	float mag = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
	float s = sin(angle);
	float c = cos(angle);
	float omc = 1 - c;

	float x = vector.x / mag;
	float y = vector.y / mag;
	float z = vector.z / mag;

	mat.data[0][0] = x * x * omc + c;		mat.data[1][0] = x * y * omc - z * s;		mat.data[2][0] = x * z * omc + y * s;
	mat.data[0][1] = x * y * omc + z * s;	mat.data[1][1] = y * y * omc + c;			mat.data[2][1] = y * z * omc - x * s;
	mat.data[0][2] = x * z * omc - y * s;	mat.data[1][2] = y * z * omc + x * s;		mat.data[2][2] = z * z * omc + c;
	mat.data[3][3] = 1.0f;

	return mat;
}

//TODO: Memory issue? Only on debug mode and taking left as a reference 
mat4 operator*(mat4 &left, mat4 &right) {
	mat4 mat;
	memset(&mat.data[0][0], 0, sizeof(mat.data[0][0]) * 4 * 4);

	float sum = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				sum += left.data[k][i] * right.data[j][k];
			}
			mat.data[j][i] = sum;
			sum = 0;
		}
	}

	return mat;
}

//TODO: For loop maybe?
vec3 operator*(mat4 &matrix, const vec3 &vector) {
	vec3 v(0.0f, 0.0f, 0.0f);
	float x = vector.x;
	float y = vector.y;
	float z = vector.z;

	v.x = matrix.data[0][0] * x + matrix.data[1][0] * y + matrix.data[2][0] * z + matrix.data[3][0];
	v.y = matrix.data[0][1] * x + matrix.data[1][1] * y + matrix.data[2][1] * z + matrix.data[3][1];
	v.z = matrix.data[0][2] * x + matrix.data[1][2] * y + matrix.data[2][2] * z + matrix.data[3][2];

	return v;
}