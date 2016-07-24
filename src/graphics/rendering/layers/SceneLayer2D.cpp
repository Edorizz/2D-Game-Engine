#include "SceneLayer2D.h"

SceneLayer2D::SceneLayer2D(std::string *shaders, Camera2D *camera) : Layer(shaders) {
	m_Camera = camera;
}

void SceneLayer2D::Draw() {
	m_Shader.Use();
		m_Shader.UniformMat4("projectionMatrix", 1, GL_FALSE, m_Camera->GetProjection().GetData());
		m_Shader.UniformMat4("viewMatrix", 1, GL_FALSE, m_Camera->GetView().GetData());
		m_Renderer.Begin();
		for (Renderable2D *renderable : m_Renderables)
			renderable->Submit(&m_Renderer);
		m_Renderer.End();
		m_Renderer.Flush();
	m_Shader.Unuse();
}

void SceneLayer2D::Add(Renderable2D *renderable) {
	m_Renderables.push_back(renderable);
}
