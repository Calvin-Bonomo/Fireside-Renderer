#include "VertexArray.h"

#include <iostream>

fireside::VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_RendererID);
}

fireside::VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_RendererID);
}

void fireside::VertexArray::Bind()
{
	glBindVertexArray(m_RendererID);
}

void fireside::VertexArray::Unbind()
{
	glBindVertexArray(0);
}

void fireside::VertexArray::AddLayout(VertexLayout& layout)
{
	auto& elements = layout.GetLayoutElements();

	unsigned int i = 0;
	unsigned int offset = 0;

	for (const VertexElement& element : elements) {
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetTotalOffset(), (void*)offset);
		++i;
		offset += element.stride * element.count;
	}
}
