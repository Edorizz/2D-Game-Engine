#pragma once

#include <glm/glm.hpp>
#include "Renderable2D.h"

namespace Sphinx {

	struct Vertex {
		glm::vec3 position;
		glm::vec4 color;
	};

	class Sprite : public Renderable2D {
	private:
		glm::vec3 m_Position;
		glm::vec2 m_Size;
		glm::vec4 m_Color;
	public:
		Sprite(const glm::vec3 &position, const glm::vec2 &dimensions, const glm::vec4 &color);
		void Render(Renderer2D renderer);
		glm::vec3& GetPosition() { return m_Position; }
		glm::vec2& GetSize() { return m_Size; }
		glm::vec4& GetColor() { return m_Color; }
	};

}