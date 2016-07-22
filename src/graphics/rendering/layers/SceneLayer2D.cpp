#include "SceneLayer2D.h"

SceneLayer2D::SceneLayer2D(std::string *shaders) : Layer(shaders) {}

void SceneLayer2D::Draw() {
	m_Shader.Use();
		m_Renderer.Begin();
		for (int i = 0; i < m_Renderables.size(); i++) {
			m_Renderables[i]->Submit(&m_Renderer);
		}
		m_Renderer.End();
		m_Renderer.Flush();
	m_Shader.Unuse();
}

void SceneLayer2D::Add(Renderable2D *renderable) {
	m_Renderables.push_back(renderable);
}
