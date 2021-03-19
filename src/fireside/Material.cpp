#include "Material.h"

fireside::Material::Material()
{
	m_Shader = nullptr;
	m_Texture = nullptr;
}

fireside::Material::Material(std::shared_ptr<Shader>& shader)
{
	m_Shader = shader;
	m_Texture = nullptr;
}

fireside::Material::Material(std::shared_ptr<Shader>& shader, std::shared_ptr<Texture>& texture)
{
	m_Shader = shader;
	m_Texture = texture;
}

void fireside::Material::Bind() 
{
	if (m_Shader != nullptr) m_Shader->Bind();
	if (m_Texture != nullptr) m_Texture->Bind();
}

void fireside::Material::Unbind()
{
	if (m_Shader != nullptr) m_Shader->Unbind();
	if (m_Texture != nullptr) m_Texture->Unbind();
}

void fireside::Material::SetShaderUniform(Uniform uniform) 
{
	switch (uniform.type)
	{
		case u_Float:
			m_Shader->SetUniform1f(uniform.name, *(GLfloat*)uniform.value);
			break;
		case u_Integer:
			std::cerr << "Not yet implemented." << std::endl;
			break;
		case u_Vec2:
			std::cerr << "Not yet implemented." << std::endl;
			break;
		case u_Vec3:
			std::cerr << "Not yet implemented." << std::endl;
			break;
		case u_Vec4:
			m_Shader->SetUniform4fv(uniform.name, *(glm::vec4*)uniform.value);
			break;
		case u_Mat4x4:
			std::cerr << "Not yet implemented." << std::endl;
			break;
		default:
			std::cerr << "Could not find uniform type " << uniform.type << "." << std::endl;
			break;
	}
}