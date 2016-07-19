#include "Group.h"
#include "Renderer2D.h"

Group::Group(glm::mat4 transform) {
	Init(transform);
}

void Group::Add(Renderable2D *renderable) {
	m_Renderables.push_back(renderable);
}

void Group::Submit(Renderer2D *renderer) {
	renderer->Push_Stack(m_TransformationMatrix);
	for (Renderable2D *r : m_Renderables) {
		r->Submit(renderer);	
	}
	renderer->Pop_Stack();
}

void Group::Init(glm::mat4 transform) {
	m_TransformationMatrix = transform;
}