#pragma once

#include <vector>

namespace fireside {
	struct VertexElement 
	{
		GLint count;
		GLenum type;
		GLboolean normalized;
		GLsizei stride;
	};

	class VertexLayout 
	{
	public:
		template <typename T>
		void Push(GLint count) 
		{
			GLsizei mySize = sizeof(T);
			m_VertexElements.push_back({count, GetType(mySize), GL_FALSE, GetStride()});
			m_TotalOffset += count * sizeof(T);
		}

		inline std::vector<VertexElement>& GetLayoutElements() { return m_VertexElements; }
		inline const GLsizei GetTotalOffset() { return m_TotalOffset; }
	private:
		GLsizei GetStride()
		{
			GLsizei totalStride = 0;
			
			for (const VertexElement& element : m_VertexElements)
				totalStride += element.count * GetSize(element.type);
			return totalStride;
		}
		GLenum GetType(GLsizei bytes)
		{
			switch (bytes)
			{
				case sizeof(float) :
					return GL_FLOAT;
				case sizeof(double) :
					return GL_DOUBLE;
			}
			return 0;
		}
		GLsizei GetSize(GLenum type)
		{
			switch (type)
			{
			case GL_FLOAT:
				return sizeof(GLfloat);
			case GL_DOUBLE:
				return sizeof(GLdouble);
			default:
				return 0;
			}
		}
	private:
		std::vector<VertexElement> m_VertexElements;
		GLsizei m_TotalOffset = 0;
	};
}