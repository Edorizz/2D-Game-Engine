#pragma once

#include "../../../math/Math.h"

class Renderer2D;

struct Vertex {
	vec3 position;
	vec4 color;
};

class Renderable2D {
public:
	virtual void Submit(Renderer2D *renderer) {};
protected:
	Renderable2D() {}
};
