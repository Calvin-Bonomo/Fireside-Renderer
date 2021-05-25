#include "Renderer.h"

#include <iostream>

fireside::Renderer2D::~Renderer2D()
{
	glfwTerminate();
}

void fireside::Renderer2D::LogError(int id, const char* description) 
{
	std::cout << "Error " << id << ": " << description << std::endl;
}

const unsigned int fireside::Renderer2D::InitRenderer(unsigned int w, unsigned int h, const char* title)
{
	// Set members
	m_IsActive = true;

	m_WindowWidth = w;
	m_WindowHeight = h;

	glfwSetErrorCallback(&LogError);

	// Initialize GLFW
	if (!glfwInit()) {
		std::cout << "GLFW failed to initialize." << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

#ifdef DEBUG
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	std::cout << "Fireside Renderer is running in debug mode." << std::endl;
#else
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

	
	// Create a windowed mode window and its OpenGL context
	m_Window = glfwCreateWindow(m_WindowWidth, m_WindowHeight, title, NULL, NULL);
	if (!m_Window)
	{
		std::cout << "GLFW failed to to create a window." << std::endl;
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(m_Window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW failed to initialize." << std::endl;
		return -1;
	}

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

void fireside::Renderer2D::doRenderCall(fireside::RenderCall call, glm::mat4x4& camMat) 
{	
	call.vertexArray.Bind();
	call.elementBuffer.Bind();
	call.material.Bind();
	
	glDrawElements(GL_TRIANGLES, call.elementBuffer.GetLength(), call.elementBuffer.GetType(), nullptr);

	call.material.Unbind();
	call.elementBuffer.Unbind();
	call.vertexArray.Unbind();
}