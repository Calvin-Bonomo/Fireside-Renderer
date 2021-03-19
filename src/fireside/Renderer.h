#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

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
		std::weak_ptr<VertexArray> vertexArray;
		std::weak_ptr<ElementArrayBuffer> elementBuffer;
		std::weak_ptr<Material> material;
		std::weak_ptr<glm::mat4x4> localMat;
	};

	class Renderer2D 
	{
	public:
		Renderer2D() : m_Window(nullptr), m_WindowHeight(1), m_WindowWidth(1) { };
		~Renderer2D();

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