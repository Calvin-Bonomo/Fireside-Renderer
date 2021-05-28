#pragma once

#include "GL/glew.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

namespace fireside {
	class Shader 
	{
	public:
		Shader(const char* vertexFilePath, const char* fragmentFilePath);
		~Shader();
		
		void Bind();
		void Unbind();

		void SetUniform1f(std::string uniform, const GLfloat value);
		void SetUniform4fv(std::string uniform, const glm::vec4 value);
		void SetUniformMatrix4fv(std::string uniform, const glm::mat4 value);
	private:
		unsigned long GetFileLength(std::ifstream& fileStream);
		std::string ReadFile(const char* filePath);

		GLuint CreateShader(GLenum shaderType, const char* shaderSource);

		GLint GetUniformLocation(std::string uniform);
	private:
		GLuint m_RendererID;
		std::unordered_map<std::string, GLint> m_UniformLocations;
	};
}