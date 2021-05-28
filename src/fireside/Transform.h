#pragma once

#include "glm/glm.hpp"
#include "glm/ext/matrix_transform.hpp"

namespace fireside 
{
	class Transform 
	{
	public:
		Transform();
		~Transform();

		void SetPosition(float xPos, float yPos);
		void SetPosition(float xPos, float yPos, float zPos);

		void SetRotation(float degrees);
		void SetScale(float xScale, float yScale);

		void Translate(float xPos, float yPos);
		void Translate(float xPos, float yPos, float zPos);

		void RotateBy(float degrees);
		void ScaleBy(float xScale, float yScale);

		glm::mat4 GetLocalTransform();

		glm::vec3 GetPosition() { return m_Position; }
		glm::vec2 GetScale() { return m_Scale; }
		float GetRotation() { return m_Rotation; }

	private:
		glm::vec3 m_Position;
		glm::vec2 m_Scale;

		float m_Rotation;
	};
}