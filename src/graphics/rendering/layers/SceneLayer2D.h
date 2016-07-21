#pragma once

#include "Layer.h"
#include "../renderers/BatchRenderer2D.h"

class SceneLayer2D : public Layer {
private:
	BatchRenderer2D m_Renderer;
public:
	void Draw();
	void Add(Renderable2D *renderable);
};
