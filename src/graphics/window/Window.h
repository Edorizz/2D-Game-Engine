#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL/SDL.h>
#include <string>
#include <iostream>
#include "../../math/Math.h"

#define MAX_KEYS 1024

class Window {
private:
	SDL_Window *m_Window;
	SDL_GLContext m_GLContext;
	GLuint m_ScreenWidth, m_ScreenHeight;
	std::string m_Title;
	GLboolean m_ShouldClose;
	GLboolean keys[MAX_KEYS];
	GLint m_MousePosX, m_MousePosY;
public:
	Window(std::string title, GLuint width, GLuint height);
	~Window();
	GLboolean ShouldClose();
	void Clear();
	void HandleInput();
	void Swap();
	void GetMousePos(vec2 *vector);
	// TODO: Add IsKeyDown and IsKeyUp
	GLboolean IsKeyPressed(GLint key);
private:
	void Init();
};