#pragma once

#include <GL/glew.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class ShaderProgram {
private:
	GLuint m_ShaderProgram;
public:
	ShaderProgram(std::string vertexPath, std::string fragmentPath);
	~ShaderProgram();
	void Use();
	void Unuse();
	GLuint GetID() { return m_ShaderProgram; }
private:
	GLuint CompileShader(std::string shaderPath, GLenum shaderType);
};