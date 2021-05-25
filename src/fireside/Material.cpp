#include "Material.h"

fireside::Material::Material(Shader* shader)
{
	m_Shader = shader;
}

fireside::Material::~Material() 
{
	delete m_Shader;
}

void fireside::Material::Bind() 
{
	if (m_Shader != nullptr) m_Shader->Bind();
	for (Uniform u : m_UniformList) 
	{
		SetShaderUniform(u);
	}
}

void fireside::Material::Unbind()
{
	for (Uniform u : m_UniformList)
	{
		if (u.type == u_Tex2D)
		{
			Texture& tex = *(Texture*)u.value;
			tex.Unbind();
		}
	}
	if (m_Shader != nullptr) m_Shader->Unbind();
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
		case u_Tex2D:
			Texture& texture = *(Texture*)uniform.value;
			texture.Bind();
			break;
	}
}