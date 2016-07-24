#pragma once

#include "../math/Math.h"

class Camera2D {
private:
	mat4 m_ProjectionMatrix;
	mat4 m_ViewMatrix;
	vec3 m_Position;
	float m_Speed;
public:
	Camera2D(mat4 projectionMatrix, vec3 position, float speed);
	void Move(vec3 direction);
	const vec3& GetPosition() { return m_Position; }
	const mat4& GetProjection() { return m_ProjectionMatrix; }
	const mat4& GetView() { return m_ViewMatrix; }
	void SetPosition(vec3 position) { m_Position = position; }
};
