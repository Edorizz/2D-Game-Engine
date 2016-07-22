#pragma once

#include <vector>
#include "../renderables/Renderable2D.h"
#include "../renderers/Renderer2D.h"
#include "../../shaders/ShaderProgram.h"

class Layer {
protected:
	std::vector<Renderable2D*>m_Renderables;
public:
	ShaderProgram m_Shader;
protected:
	Layer(std::string *shaders) : m_Shader(shaders[0], shaders[1]) {};
public:
	virtual void Draw() = 0;
	virtual void Add(Renderable2D *renderable) = 0;
};
