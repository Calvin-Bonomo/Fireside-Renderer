#include "ElementArrayBuffer.h"

fireside::ElementArrayBuffer::ElementArrayBuffer(const void* data, GLsizeiptr size, unsigned int length) : m_ElementBufferLength(length), m_ElementType(0)
{
	switch (size/length)
	{
		case sizeof(unsigned char) :
			m_ElementType = GL_UNSIGNED_BYTE;
			break;
		case sizeof(unsigned int) :
			m_ElementType = GL_UNSIGNED_INT;
			break;
	}
	glGenBuffers(1, &m_RendererID);
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	Unbind();
}

fireside::ElementArrayBuffer::~ElementArrayBuffer()
{
	glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &m_RendererID);
}

void fireside::ElementArrayBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void fireside::ElementArrayBuffer::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

