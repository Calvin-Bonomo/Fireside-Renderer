#pragma once

#include "GL/glew.h"

namespace fireside {

	class VertexBuffer 
	{
	public:
		VertexBuffer(const void* data, GLsizeiptr size);
		~VertexBuffer();

		void Bind();
		void Unbind();
	private:
		GLuint m_RendererID;
	};
}