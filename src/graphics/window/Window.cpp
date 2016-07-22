#include "Window.h"

Window::Window(std::string title, GLuint width, GLuint height)
	: m_Title(title), m_ScreenWidth(width), m_ScreenHeight(height), m_ShouldClose(false), m_MousePosX(0), m_MousePosY(0){
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
			SDL_GL_SetSwapInterval(1);
		}
	}
}

GLboolean Window::ShouldClose() {
	return m_ShouldClose;
}

void Window::Clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

//TODO MAKE YOUR OWN INPUT MANAGER CLASS!
void Window::HandleInput() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_KEYDOWN:
			keys[e.key.keysym.scancode] = true;
			break;
		case SDL_KEYUP:
			keys[e.key.keysym.scancode] = false;
			break;
		case SDL_QUIT:
			m_ShouldClose = true;
			break;
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&m_MousePosX, &m_MousePosY);
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

void Window::GetMousePos(vec2 *vector) {
	vector->x = m_MousePosX;
	vector->y = m_MousePosY;
}