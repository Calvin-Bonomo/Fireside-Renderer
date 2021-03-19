#pragma once

#include "Shader.h"
#include "Texture.h"

#include <vector>

#include "glm/glm.hpp"

// Define uniform types for easy uniform setting
#define UniformType unsigned int
#define u_Float 0
#define u_Integer 1
#define u_Vec2 2
#define u_Vec3 3
#define u_Vec4 4
#define u_Mat4x4 5

namespace fireside {
	struct Uniform {
		std::string name;
		UniformType type;
		const void* value;
	};

	class Material 
	{
	public:
		Material();
		Material(Shader* shader);
		Material(Shader* shader, Texture* texture);

		~Material();

		void Bind();
		void Unbind();

		void AddUniform(std::string name, UniformType type, const void* value) { m_UniformList.push_back({ name, type, value }); }

		void SetShaderUniform(Uniform uniform);

	private:
		Shader m_Shader;
		Texture m_Texture;
		std::vector<Uniform> m_UniformList;
	};
}