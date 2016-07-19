#include "BatchRenderer2D.h"

BatchRenderer2D::BatchRenderer2D() {
	Init();
}

BatchRenderer2D::~BatchRenderer2D() {
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ibo);
}

void BatchRenderer2D::Init() {
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, RENDERER_VERTEX_BUFFER_SIZE, nullptr, GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray(SHADER_POSITION_INDEX);
		glEnableVertexAttribArray(SHADER_POSITION_INDEX);

		glVertexAttribPointer(SHADER_POSITION_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)offsetof(Vertex, position));
		glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)offsetof(Vertex, color));

	GLuint indices[RENDERER_INDEX_BUFFER_SIZE];

	GLuint offset = 0;
	for (int i = 0; i < RENDERER_INDEX_BUFFER_SIZE; i += 6) {
		indices[  i  ] = offset + 0;
		indices[i + 1] = offset + 1;
		indices[i + 2] = offset + 2;
		indices[i + 3] = offset + 2;
		indices[i + 4] = offset + 3;
		indices[i + 5] = offset + 0;
	}

		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glBindVertexArray(0);
}

void BatchRenderer2D::Begin() {
	glBindVertexArray(vao);
	m_Buffer = (Vertex*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
}

//! OPTIMIZE THIS!
void BatchRenderer2D::Submit(Sprite *renderable) {
	const glm::vec3 &position = renderable->GetPosition();
	const glm::vec2 &size = renderable->GetSize();
	const glm::vec4 &color = renderable->GetColor();

	m_Buffer->position = glm::vec3(*m_TransformationBack * glm::vec4(position, 1.0f));
	m_Buffer->color = color;
	m_Buffer++;

	m_Buffer->position = glm::vec3(*m_TransformationBack * glm::vec4(position.x, position.y + size.y, position.z, 1.0f));
	m_Buffer->color = color;
	m_Buffer++;

	m_Buffer->position = glm::vec3(*m_TransformationBack * glm::vec4(position.x + size.x, position.y + size.y, position.z, 1.0f));
	m_Buffer->color = color;
	m_Buffer++;

	m_Buffer->position = glm::vec3(*m_TransformationBack * glm::vec4(position.x + size.x, position.y, position.z, 1.0f));
	m_Buffer->color = color;
	m_Buffer++;
}

void BatchRenderer2D::End() {
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindVertexArray(0);
}

void BatchRenderer2D::Flush() {
	glBindVertexArray(vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glDrawElements(GL_TRIANGLES, RENDERER_INDEX_BUFFER_SIZE, GL_UNSIGNED_INT, nullptr);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(vao);
}