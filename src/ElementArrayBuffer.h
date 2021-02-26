#pragma once

#include "GL/glew.h"

namespace fireside { // TODO: Add template specialization for unsigned int and unsigned char 

	class ElementArrayBuffer
	{
	public:
		ElementArrayBuffer(const void* data, GLsizeiptr size);
		~ElementArrayBuffer();

		void Bind();
		void Unbind();
	private:
		GLuint m_RendererID;
		GLenum m_ElementType;
	};
}