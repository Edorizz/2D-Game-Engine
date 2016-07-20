#include "Sprite.h"
#include "Renderer2D.h"

Sprite::Sprite(const vec3 &position, const vec2 &dimensions, const vec4 &color)
	: m_Position(position), m_Size(dimensions), m_Color(color) {
}

void Sprite::Submit(Renderer2D *renderer) {
	renderer->Submit(this);
}