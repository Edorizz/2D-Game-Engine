#include "Math_func.h"

float ToRadians(float degrees) {
	return degrees / (180.0f / PI);
}

float ToDegrees(float radians) {
	return radians * (180.0f / PI);
}
