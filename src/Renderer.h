#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "VertexBuffer.h"
#include "ElementArrayBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

namespace fireside {

	class Application
	{
	public:
		virtual unsigned int Render() = 0;
	};

	class Renderer2D 
	{
	public:
		Renderer2D();
		~Renderer2D();

		const unsigned int InitRenderer(unsigned int w, unsigned int h, const char* title);
		void Start(fireside::Application* app);

		inline GLFWwindow* getWindow() { return m_IsActive ? m_Window : nullptr; }
	private:
		bool m_IsActive = false;

		GLFWwindow* m_Window;
		unsigned int m_WindowWidth;
		unsigned int m_WindowHeight;
	};
}