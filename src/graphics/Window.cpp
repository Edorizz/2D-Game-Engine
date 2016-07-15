#include "Window.h"

namespace Sphinx {

	Window::Window(std::string title, GLuint width, GLuint height)
		: m_Title(title), m_ScreenWidth(width), m_ScreenHeight(height), m_ShouldClose(false) {
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			std::cout << "Failed to initialize SDL! SDL_Error: " << SDL_GetError() << std::endl;
		} else {
			Init();
		}
	}

	Window::~Window() {
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
	}

	void Window::Init() {
		m_Window = SDL_CreateWindow(m_Title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_ScreenWidth, m_ScreenHeight, SDL_WINDOW_OPENGL);
		if (!m_Window) {
			std::cout << "Failed to create window! SDL_Error: " << SDL_GetError() << std::endl;
		} else {
			m_GLContext = SDL_GL_CreateContext(m_Window);
			if (!m_GLContext) {
				std::cout << "Failed to create GLContext! SDL_Error: " << SDL_GetError() << std::endl;
			} else {
				glewInit();
				SDL_GL_SetSwapInterval(0);
			}
		}
	}

	GLboolean Window::ShouldClose() {
		return m_ShouldClose;
	}

	//TODO MAKE YOUR OWN INPUT MANAGER CLASS!
	void Window::HandleInput() {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_KEYDOWN:
				keys[e.key.keysym.scancode] = true;
			case SDL_KEYUP:
				keys[e.key.keysym.scancode] = false;
			case SDL_QUIT:
				m_ShouldClose = true;
			default:
				break;
			}
		}
		if (keys[SDL_SCANCODE_ESCAPE]) {
			m_ShouldClose = true;
		}
	}

	void Window::Swap() {
		SDL_GL_SwapWindow(m_Window);
	}

}