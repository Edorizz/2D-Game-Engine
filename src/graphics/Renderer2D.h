#pragma once

#include <deque>
#include <GL/glew.h>
#include "Sprite.h"
#include "ShaderProgram.h"

namespace Sphinx {

	class Renderer2D {
	private:
		GLuint vao, vbo, ibo;
		std::deque<Renderable2D*>m_RenderQueue;
	public:
		Renderer2D();
		void Submit(Sprite &sprite);
		void Flush();
	};

}
