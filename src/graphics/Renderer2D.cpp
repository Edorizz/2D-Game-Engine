#include "Renderer2D.h"
#include "Sprite.h"

void Renderer2D::Push_Stack(mat4 &transform) {
	m_TransformationStack.push_back(transform);
	m_TransformationBack = &transform;
}

void Renderer2D::Pop_Stack() {
	if (m_TransformationStack.size() > 1) {
		m_TransformationStack.pop_back();
		m_TransformationBack = &m_TransformationStack.back();
	}
}