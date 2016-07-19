#pragma once

#include <glm/glm.hpp>
#include "Renderable2D.h"

class Sprite : public Renderable2D {
private:
	glm::vec3 m_Position;
	glm::vec2 m_Size;
	glm::vec4 m_Color;
public:
	Sprite(const glm::vec3 &position, const glm::vec2 &dimensions, const glm::vec4 &color);
	void Submit(Renderer2D *renderer);
	const glm::vec3& GetPosition() { return m_Position; }
	const glm::vec2& GetSize() { return m_Size; }
	const glm::vec4& GetColor() { return m_Color; }
};