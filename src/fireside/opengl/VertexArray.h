#pragma once

#include "GL/glew.h"

#include "VertexLayout.h"

namespace fireside {

	class VertexArray 
	{
	public:
		VertexArray();
		~VertexArray();

		void Bind();
		void Unbind();

		void AddLayout(VertexLayout& layout);
	private:
		GLuint m_RendererID;
	};
}