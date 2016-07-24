#pragma once

#include "Layer.h"

class UILayer : public Layer {
public:
	UILayer(std::string *shaders);
	void Draw();
	void Add(Renderable2D *renderable);
};
