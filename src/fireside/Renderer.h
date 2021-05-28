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
#include "Camera.h"

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
		Transform& transform;
	};

	class Renderer2D 
	{
	public:
		Renderer2D() : m_Window(nullptr), m_WindowHeight(1), m_WindowWidth(1) { };
		~Renderer2D();

		static void logError(int id, const char* description);

		const unsigned int InitRenderer(unsigned int w, unsigned int h, const char* title, Camera& mainCamera);
		void Start(fireside::Application* app);

		static void doRenderCall(RenderCall call, Camera& renderCamera);

		inline GLFWwindow* getWindow() { return m_Window; }
	private:
		GLFWwindow* m_Window;
		unsigned int m_WindowWidth;
		unsigned int m_WindowHeight;
	};
}