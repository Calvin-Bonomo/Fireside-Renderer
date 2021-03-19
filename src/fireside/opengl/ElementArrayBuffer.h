#pragma once

#include "GL/glew.h"

namespace fireside { // TODO: Add template specialization for unsigned int and unsigned char 

	class ElementArrayBuffer
	{
	public:
		ElementArrayBuffer(const void* data, GLsizeiptr size, unsigned int length);
		~ElementArrayBuffer();

		void Bind();
		void Unbind();

		const GLenum getType() { return m_ElementType; }
		const unsigned int getLength() { return m_ElementBufferLength; }
	private:
		GLuint m_RendererID;
		GLenum m_ElementType;
		unsigned int m_ElementBufferLength;
	};
}