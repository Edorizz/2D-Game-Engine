#include "Sprite.h"
#include "Renderer2D.h"

Sprite::Sprite(const glm::vec3 &position, const glm::vec2 &dimensions, const glm::vec4 &color)
	: m_Position(position), m_Size(dimensions), m_Color(color) {
}

void Sprite::Submit(Renderer2D *renderer) {
	renderer->Submit(this);
}