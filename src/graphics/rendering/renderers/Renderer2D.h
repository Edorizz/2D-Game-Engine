#pragma once

#include <deque>
#include <GL/glew.h>
#include "../../shaders/ShaderProgram.h"
#include "../../../math/Math.h"

class Sprite;

class Renderer2D {
protected:
	GLuint vao, vbo, ibo;
	std::vector<mat4>m_TransformationStack;
	mat4 *m_TransformationBack;
protected:
	Renderer2D();
public:
	virtual void Init() = 0;
	void Push_Stack(mat4 &transform);
	void Pop_Stack();
	virtual void Begin() = 0;
	virtual void Submit(Sprite *sprite) = 0;
	virtual void End() = 0;
	virtual void Flush() = 0;
};