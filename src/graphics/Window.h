#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL/SDL.h>
#include <string>
#include <iostream>

#define MAX_KEYS 1024

namespace Sphinx {

	class Window {
	private:
		SDL_Window *m_Window;
		SDL_GLContext m_GLContext;
		GLuint m_ScreenWidth, m_ScreenHeight;
		std::string m_Title;
		GLboolean m_ShouldClose;
		GLboolean keys[MAX_KEYS];
	public:
		Window(std::string title, GLuint width, GLuint height);
		~Window();
		GLboolean ShouldClose();
		void HandleInput();
		void Swap();
	private:
		void Init();
	};

}

