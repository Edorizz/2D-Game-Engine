#pragma once

class Renderer2D;
#include "../math/Math.h"

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