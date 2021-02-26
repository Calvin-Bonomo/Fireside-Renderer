#include "Renderer.h"

#include <iostream>

fireside::Renderer2D::Renderer2D()
{

}

fireside::Renderer2D::~Renderer2D()
{
	glfwTerminate();
}

const unsigned int fireside::Renderer2D::InitRenderer(unsigned int w, unsigned int h, const char* title)
{
	// Set members
	m_IsActive = true;

	m_WindowWidth = w;
	m_WindowHeight = h;

	// Initialize GLFW
	if (!glfwInit())
		return -1;

	// Create a windowed mode window and its OpenGL context
	m_Window = glfwCreateWindow(m_WindowWidth, m_WindowHeight, title, NULL, NULL);
	if (!m_Window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(m_Window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK)
		return -1;

	return 0; // Successful initialization
}

void fireside::Renderer2D::Start(fireside::Application* app)
{
	while (!glfwWindowShouldClose(m_Window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		app->Render();

		// Swap front and back buffers
		glfwSwapBuffers(m_Window);

		// Poll for and process events
		glfwPollEvents();
	}
}