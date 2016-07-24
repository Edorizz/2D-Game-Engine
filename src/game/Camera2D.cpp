#include "Camera2D.h"

Camera2D::Camera2D(mat4 projection, vec3 position, float speed)
	: m_Position(position), m_ProjectionMatrix(projection), m_ViewMatrix(mat4::Translate(-position)), m_Speed(speed) {}

void Camera2D::Move(vec3 direction) {
	direction = vec3::Normalize(direction);
	m_Position += (direction * m_Speed);
	m_ViewMatrix = mat4::Translate(-m_Position);
}