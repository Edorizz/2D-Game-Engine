#include "UILayer.h"

UILayer::UILayer(std::string *shaders) : Layer(shaders) {}

void UILayer::Draw() {
	m_Shader.Use();
		m_Renderer.Begin();
		for (Renderable2D *renderable : m_Renderables)
			renderable->Submit(&m_Renderer);
		m_Renderer.End();
		m_Renderer.Flush();
	m_Shader.Unuse();
}

void UILayer::Add(Renderable2D *renderable) {
	m_Renderables.push_back(renderable);
}
