#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(std::string &vertexPath, std::string &fragmentPath) : m_Enabled(false) {
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
	m_Enabled = true;
}

void ShaderProgram::Unuse() {
	glUseProgram(0);
	m_Enabled = false;
}

void ShaderProgram::Uniform2f(std::string name, vec2 vector, GLboolean disableAfterUse) {
	if (!m_Enabled)
		Use();
	glUniform2f(GetUniformLocation(name), vector.x, vector.y);
	if (disableAfterUse)
		Unuse();
}

void ShaderProgram::Uniform3f(std::string name, vec3 vector, GLboolean disableAfterUse) {
	if (!m_Enabled)
		Use();
	glUniform3f(GetUniformLocation(name), vector.x, vector.y, vector.z);
	if (disableAfterUse)
		Unuse();
}

void ShaderProgram::UniformMat4(std::string name, GLuint count, GLboolean transpose, const GLfloat *matrixData, GLboolean disableAfterUse) {
	if (!m_Enabled)
		Use();
	glUniformMatrix4fv(GetUniformLocation(name), count, transpose, matrixData);
	if (disableAfterUse)
		Unuse();
}

GLint ShaderProgram::GetUniformLocation(std::string name) {
	return glGetUniformLocation(m_ShaderProgram, name.c_str());
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