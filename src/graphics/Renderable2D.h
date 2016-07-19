#pragma once

class Renderer2D;
#include <GLM/glm.hpp>

struct Vertex {
	glm::vec3 position;
	glm::vec4 color;
};

class Renderable2D {
public:
	virtual void Submit(Renderer2D *renderer) {};
protected:
	Renderable2D() {}
};