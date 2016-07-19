#pragma once

#include "Renderable2D.h"
#include <GLM/glm.hpp>
#include <vector>

class Group : public Renderable2D {
private:
	glm::mat4 m_TransformationMatrix;
	std::vector<Renderable2D*>m_Renderables;
public:
	Group(glm::mat4 transform);
	void Init(glm::mat4 transform);
	void Add(Renderable2D *renderable);
	void Submit(Renderer2D *renderer);
};

