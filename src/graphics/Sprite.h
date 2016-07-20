#pragma once

#include "Renderable2D.h"

class Sprite : public Renderable2D {
private:
	vec3 m_Position;
	vec2 m_Size;
	vec4 m_Color;
public:
	Sprite(const vec3 &position, const vec2 &dimensions, const vec4 &color);
	void Submit(Renderer2D *renderer);
	const vec3& GetPosition() { return m_Position; }
	const vec2& GetSize() { return m_Size; }
	const vec4& GetColor() { return m_Color; }
};