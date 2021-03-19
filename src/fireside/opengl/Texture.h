#pragma once

#include "GLFW/glfw3.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

namespace fireside {
	class Texture 
	{
	public:
		Texture();
		~Texture();

		void Bind();
		void Unbind();

		void CreateTexture(const char* path);

	private:
		GLuint m_RendererID;
	};
}