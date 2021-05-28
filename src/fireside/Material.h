#pragma once

#include "Shader.h"
#include "Texture.h"

#include <vector>

#include "glm/glm.hpp"

// Define uniform types for easy uniform setting
typedef unsigned int UniformType;
const UniformType u_Float = 0;
const UniformType u_Integer = 1;
const UniformType u_Vec2 = 2;
const UniformType u_Vec3 = 3;
const UniformType u_Vec4 = 4;
const UniformType u_Mat4 = 5;
const UniformType u_Tex2D = 6;

namespace fireside {
	struct Uniform {
		std::string name;
		UniformType type;
		const void* value;
	};

	class Material 
	{
	public:
		Material(Shader* shader);

		~Material();

		void Bind();
		void Unbind();

		void AddUniform(std::string name, UniformType type, const void* value) { m_UniformList.push_back({ name, type, value }); }
	private:
		void SetShaderUniform(Uniform uniform);

	private:
		Shader* m_Shader;
		std::vector<Uniform> m_UniformList;
	};
}