#include "SceneLayer2D.h"

void SceneLayer2D::Draw() {
	m_Renderer.Begin();
	for (int i = 0; i < m_Renderables.size(); i++) {
		m_Renderables[i]->Submit(&m_Renderer);
	}
	m_Renderer.End();
	m_Renderer.Flush();
}

void SceneLayer2D::Add(Renderable2D *renderable) {
	m_Renderables.push_back(renderable);
}
