#include "Shader.h"

fireside::Shader::Shader(const char* vertexFilePath, const char* fragmentFilePath) 
{
	unsigned int vID = CreateShader(GL_VERTEX_SHADER, vertexFilePath);
	unsigned int fID = CreateShader(GL_FRAGMENT_SHADER, fragmentFilePath);

	m_RendererID = glCreateProgram();
	glAttachShader(m_RendererID, vID);
	glAttachShader(m_RendererID, fID);
	glLinkProgram(m_RendererID);
	glValidateProgram(m_RendererID);

	glDeleteShader(vID);
	glDeleteShader(fID);
}

fireside::Shader::~Shader() 
{
	glDeleteProgram(m_RendererID);
}

void fireside::Shader::Bind() 
{
	glUseProgram(m_RendererID);
}

void fireside::Shader::Unbind()
{
	glUseProgram(0);
}

unsigned long fireside::Shader::GetFileLength(std::ifstream& file) 
{
	// Check stream state
	if (!file.good()) return 0;

	// Get the start of the file
	unsigned long pos = file.tellg();
	// Set where to start counting and read to the end
	file.seekg(0, std::ios::end);
	// Rewind to the start of the file
	unsigned long len = file.tellg();
	file.seekg(std::ios::beg);
	// Return the length of the readable file
	return len;
}

std::string fireside::Shader::ReadFile(const char* filePath) {
	std::string content;
	std::ifstream fileStream(filePath, std::ios::in);

	if (!fileStream.is_open()) {
		std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
		return "";
	}

	std::string line = "";
	while (!fileStream.eof()) {
		std::getline(fileStream, line);
		content.append(line + "\n");
	}

	fileStream.close();
	return content;
}


GLuint fireside::Shader::CreateShader(GLenum shaderType, const char* shaderFilePath) 
{
	std::string str_shaderSource = ReadFile(shaderFilePath);
	const char* shaderSource = str_shaderSource.c_str();
	unsigned int id = glCreateShader(shaderType);
	glShaderSource(id, 1, &shaderSource, NULL);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile "
			<< ((shaderType == GL_VERTEX_SHADER) ? "vertex" : "fragment")
			<< " shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}
	else 
	{
		std::cout << "Loaded " << ((shaderType == GL_VERTEX_SHADER) ? "vertex" : "fragment") << " shader at " << shaderFilePath << std::endl;
	}

	return id;
}

void fireside::Shader::SetUniform1f(std::string uniform, const GLfloat value) { glUniform1f(GetUniformLocation(uniform), value); }

void fireside::Shader::SetUniform4fv(std::string uniform, const glm::vec4 value) { glUniform4fv(GetUniformLocation(uniform), 1, glm::value_ptr(value)); }

GLint fireside::Shader::GetUniformLocation(std::string uniform) 
{
	if (m_UniformLocations.find(uniform) != m_UniformLocations.end())
		return m_UniformLocations[uniform];

	int location = glGetUniformLocation(m_RendererID, uniform.c_str());
	if (location != -1) {
		m_UniformLocations.insert({ uniform, location });
		return location;
	}
	else 
		std::cerr << "Could not find uniform " << uniform << "." << std::endl;
}