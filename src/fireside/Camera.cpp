#include "Camera.h"

fireside::Camera::Camera() 
{}

void fireside::Camera::CreateCamera(float width, float height) 
{
	m_CameraTransform = Transform();
	m_CameraTransform.SetPosition(0.0f, 0.0f, 10.0f);
	m_Projection = glm::ortho(width / 2, -width / 2, -height / 2, height / 2, 0.1f, 1000.0f);
}

fireside::Camera::~Camera()
{
}

glm::mat4 fireside::Camera::GetViewMatrix()
{
	return glm::lookAt(m_CameraTransform.GetPosition(), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}
glm::mat4 fireside::Camera::GetProjectionMatrix()
{
	return m_Projection;
}