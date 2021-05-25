#pragma once

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "GL/glew.h"

#include "glm/glm.hpp"

#include "vector"

#include "VertexBuffer.h"
#include "ElementArrayBuffer.h"
#include "VertexArray.h"
#include "Material.h"

namespace fireside {

	class Application
	{
	public:
		virtual unsigned int Render() = 0;
	};

	struct RenderCall
	{
		VertexArray& vertexArray;
		ElementArrayBuffer& elementBuffer;
		Material& material;
	};

	class Renderer2D 
	{
	public:
		Renderer2D() : m_Window(nullptr), m_WindowHeight(1), m_WindowWidth(1) { };
		~Renderer2D();

		static void LogError(int id, const char* description);

		const unsigned int InitRenderer(unsigned int w, unsigned int h, const char* title);
		void Start(fireside::Application* app);

		static void doRenderCall(RenderCall call, glm::mat4x4& camMat);

		inline GLFWwindow* getWindow() { return m_IsActive ? m_Window : nullptr; }
	private:
		bool m_IsActive = false;

		GLFWwindow* m_Window;
		unsigned int m_WindowWidth;
		unsigned int m_WindowHeight;
	};
}