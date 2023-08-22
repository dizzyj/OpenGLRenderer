#include "Camera.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

Camera::Camera(): cameraTarget(glm::vec3(0.0f,0.0f,0.0f)), cameraPos(glm::vec3(0.0f,0.0f,3.0f)), up(glm::vec3(0.0f,1.0f,0.0f)), cameraFront(glm::vec3 (0.0f,0.0f,-1.0f)), m_fov(45)
{
	cameraDirection = glm::normalize(cameraPos - cameraTarget);
	cameraRight = glm::normalize(glm::cross(up, cameraDirection));
	cameraUp = glm::cross(cameraDirection, cameraRight);
}

glm::mat4 Camera::RotateDemo()
{
	const float radius = 10.0f;
	float camX = sin(glfwGetTime()) * radius;
	float camZ = cos(glfwGetTime()) * radius;
	glm::mat4 view;
	view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));

	return view;
}

glm::mat4 Camera::GetView()
{
	glm::vec3 direction;
	direction.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	direction.y = sin(glm::radians(m_pitch));
	direction.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	cameraFront = glm::normalize(direction);
	
	return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}
glm::mat4 Camera::GetProjection() 
{
	return glm::perspective(glm::radians(m_fov), 1920.0f / 1080.0f, 0.1f, 100.0f);;
}

void Camera::MoveForward(float deltaTime)
{
	cameraPos += cameraSpeed * cameraFront * deltaTime;
	cameraPos.y = 0.0f; // <-- this one-liner keeps the user at the ground level (xz plane)
}

void Camera::MoveBackward(float deltaTime)
{	
	cameraPos -= cameraSpeed * cameraFront * deltaTime;
	cameraPos.y = 0.0f; // <-- this one-liner keeps the user at the ground level (xz plane)
}

void Camera::MoveLeft(float deltaTime)
{
	cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * deltaTime;
	cameraPos.y = 0.0f; // <-- this one-liner keeps the user at the ground level (xz plane)
}

void Camera::MoveRight(float deltaTime)
{
	cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * deltaTime;
	cameraPos.y = 0.0f; // <-- this one-liner keeps the user at the ground level (xz plane)
}

void Camera::Update(float pitch, float yaw, float fov)
{
	m_pitch = pitch;
	m_yaw = yaw;
	m_fov = fov;

}
