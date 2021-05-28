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

// Creates an empty texture of width and height with a specified colorFormat
void fireside::Texture::CreateTexture(int width, int height, GLenum colorFormat) 
{
	unsigned char* data = new unsigned char[width * height * 3];

	Bind();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, colorFormat, GL_UNSIGNED_BYTE, data);

	Unbind();

	delete data;
}

// Loads a texture in from a png image
void fireside::Texture::LoadTexture(const char* path)
{
	glBindTexture(GL_TEXTURE_2D, m_RendererID);

	int width, height, nrChannels;
	unsigned char* imageData = stbi_load(path, &width, &height, &nrChannels, 0);

	if (imageData) {
		std::cout << "Loaded image " << path << std::endl;

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
		stbi_image_free(imageData);
	}
	else
		std::cerr << "Failed to load image " << path << "." << std::endl;
}