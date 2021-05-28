#include "Transform.h"

fireside::Transform::Transform() 
{
	m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
	m_Rotation = 0.0f;
	m_Scale    = glm::vec2(1.0f, 1.0f);
}

fireside::Transform::~Transform() 
{
}

void fireside::Transform::SetPosition(float xPos, float yPos) 
{
	m_Position = glm::vec3(xPos, yPos, m_Position.z);
}

void fireside::Transform::SetPosition(float xPos, float yPos, float zPos) 
{
	m_Position = glm::vec3(xPos, yPos, zPos);
}

void fireside::Transform::SetRotation(float degrees)
{
	m_Rotation = glm::radians(degrees);
}

void fireside::Transform::SetScale(float xScale, float yScale)
{
	m_Scale = glm::vec2(xScale, yScale);
}

void fireside::Transform::Translate(float xPos, float yPos)
{
	m_Position += glm::vec3(xPos, yPos, m_Position.z);
}

void fireside::Transform::Translate(float xPos, float yPos, float zPos) 
{
	m_Position += glm::vec3(xPos, yPos, m_Position.z);
}

void fireside::Transform::RotateBy(float degrees)
{
	m_Rotation += glm::radians(degrees);
}

void fireside::Transform::ScaleBy(float xScale, float yScale)
{
	m_Scale += glm::vec2(xScale, yScale);
}

glm::mat4 fireside::Transform::GetLocalTransform()
{
	glm::mat4 local = glm::translate(glm::identity<glm::mat4>(), m_Position);
	local = glm::rotate(local, m_Rotation, glm::vec3(0.0f, 0.0f, 1.0f));
	local = glm::scale(local, glm::vec3(m_Scale, 0.0f));
	return glm::transpose(local);
}