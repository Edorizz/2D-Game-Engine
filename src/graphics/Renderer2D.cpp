#include "Renderer2D.h"

namespace Sphinx {

	Renderer2D::Renderer2D() {
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glGenBuffers(1, &ibo);

		GLushort indices[6]{ 0, 1, 2, 2, 3, 0 };
		glBindVertexArray(vao);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		glBindVertexArray(0);
	}

	void Renderer2D::Submit(Sprite &sprite) {
		m_RenderQueue.push_back(&sprite);
		//glBindVertexArray(vao);
		//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
		//	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 4, sprite.GetVertices(), GL_DYNAMIC_DRAW);

		//	glEnableVertexAttribArray(0);
		//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

		//	glEnableVertexAttribArray(1);
		//	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));

		//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

		//	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
		//glBindVertexArray(0);
	}

	void Renderer2D::Flush() {
		while (!m_RenderQueue.empty()){
			Renderable2D* sprite = m_RenderQueue.front();
			m_RenderQueue.pop_front();
		}
	}

}