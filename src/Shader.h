#pragma once

#include "GL/glew.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

namespace fireside {

	class Shader 
	{
	public:
		Shader(const char* vertexFilePath, const char* fragmentFilePath);
		~Shader();
		
		void Bind();
		void Unbind();

		void setUniform1f(const char* uniform, const GLfloat value);
		void setUniform4fv(const char* uniform, const glm::vec4 value);
	private:
		unsigned long GetFileLength(std::ifstream& fileStream);
		std::string ReadFile(const char* filePath);

		GLuint CreateShader(GLenum shaderType, const char* shaderSource);

		inline GLint GetUniformLocation(const char* uniform) { return glGetUniformLocation(m_RendererID, uniform); }
	private:
		GLuint m_RendererID;
	};
}