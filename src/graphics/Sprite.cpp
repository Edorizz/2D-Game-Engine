#include "Sprite.h"

namespace Sphinx {

	Sprite::Sprite(const glm::vec3 &position, const glm::vec2 &dimensions, const glm::vec4 &color)
		: m_Position(position), m_Size(dimensions), m_Color(color) {
	}

}