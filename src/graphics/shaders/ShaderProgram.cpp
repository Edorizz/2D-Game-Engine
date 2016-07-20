#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(std::string &vertexPath, std::string &fragmentPath) {
	GLuint vertexShader = CompileShader(vertexPath, GL_VERTEX_SHADER);
	GLuint fragmentShader = CompileShader(fragmentPath, GL_FRAGMENT_SHADER);

	m_ShaderProgram = glCreateProgram();
	glAttachShader(m_ShaderProgram, vertexShader);
	glAttachShader(m_ShaderProgram, fragmentShader);
	glLinkProgram(m_ShaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(m_ShaderProgram);
}

void ShaderProgram::Use() {
	glUseProgram(m_ShaderProgram);
}

void ShaderProgram::Unuse() {
	glUseProgram(0);
}

GLuint ShaderProgram::CompileShader(std::string &shaderPath, GLenum shaderType) {
	std::ifstream file(shaderPath.c_str());
	if (file.fail())
		std::cout << "Failed to open " + shaderPath + '\n';

	std::string shaderSource = "";
	std::string line;
	while (std::getline(file, line)) {
		shaderSource += line + '\n';
	}

	GLuint shader = glCreateShader(shaderType);
	const char* c = shaderSource.c_str();
	glShaderSource(shader, 1, &c, nullptr);
	glCompileShader(shader);

	GLint shaderStatus;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &shaderStatus);
	if (!shaderStatus) {
		GLint logLenght = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLenght);
		std::vector<GLchar>errorLog(logLenght);
		glGetShaderInfoLog(shader, logLenght, &logLenght, &errorLog[0]);
		std::cout << "Failed to compile " + shaderPath << &errorLog[0] << std::endl;
	}
	return shader;
}