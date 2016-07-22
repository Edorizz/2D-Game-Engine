#pragma once

#include "Layer.h"
#include "../renderers/BatchRenderer2D.h"

class SceneLayer2D : public Layer {
public:
	BatchRenderer2D m_Renderer;
public:
	SceneLayer2D(std::string *shaders);
	void Draw();
	void Add(Renderable2D *renderable);
};
