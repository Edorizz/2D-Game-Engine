#pragma once

#include <GL/glew.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../../math/Math.h"

class ShaderProgram {
private:
	GLuint m_ShaderProgram;
	GLboolean m_Enabled;
public:
	ShaderProgram(std::string &vertexPath, std::string &fragmentPath);
	~ShaderProgram();
	void Use();
	void Unuse();
	void Uniform2f(std::string name, vec2 vector, GLboolean disableAfterUse = false);
	void Uniform3f(std::string name, vec3 vector, GLboolean disableAfterUse = false);
	void UniformMat4(std::string name, GLuint count, GLboolean transpose, const GLfloat *matrixData, GLboolean disableAfterUse = false);
	GLuint GetID() { return m_ShaderProgram; }
private:
	GLint GetUniformLocation(std::string name);
	GLuint CompileShader(std::string &shaderPath, GLenum shaderType);
};