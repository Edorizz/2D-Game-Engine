#pragma once

#include <vector>
#include "../renderables/Renderable2D.h"
#include "../renderers/Renderer2D.h"

class Layer {
protected:
	std::vector<Renderable2D*>m_Renderables;
public:
	virtual void Draw() = 0;
	virtual void Add(Renderable2D *renderable) = 0;
};
