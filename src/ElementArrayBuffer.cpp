#include "ElementArrayBuffer.h"

fireside::ElementArrayBuffer::ElementArrayBuffer(const void* data, GLsizeiptr size)
{
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

