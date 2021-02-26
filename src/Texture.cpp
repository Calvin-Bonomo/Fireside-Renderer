#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

fireside::Texture::Texture() 
{
	glGenTextures(1, &m_RendererID);
}

fireside::Texture::~Texture() 
{
	glDeleteTextures(1, &m_RendererID);
}

void fireside::Texture::Bind() 
{
	glBindTexture(GL_TEXTURE_2D, m_RendererID);
}

void fireside::Texture::Unbind() 
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void fireside::Texture::CreateTexture(const char* path) 
{
	glBindTexture(GL_TEXTURE_2D, m_RendererID);

	int width, height, nrChannels;
	unsigned char* imageData = stbi_load(path, &width, &height, &nrChannels, 0);

	if (imageData)
	{
		std::cout << "Loaded image " << path << std::endl;

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
		stbi_image_free(imageData);
	}
	else
		std::cerr << "Failed to load image " << path << "." << std::endl;
}