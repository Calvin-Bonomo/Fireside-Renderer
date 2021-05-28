#pragma once

#include "Transform.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_inverse.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace fireside
{
	class Camera 
	{
	public:
		Camera();
		~Camera();

		void CreateCamera(float width, float height);

		glm::mat4 GetViewMatrix();
		glm::mat4 GetProjectionMatrix();
	private:
		glm::mat4 m_Projection;
		Transform m_CameraTransform;
	};
}