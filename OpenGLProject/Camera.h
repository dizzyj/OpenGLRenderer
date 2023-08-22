#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>


class Camera
{
private:
	glm::vec3 cameraPos;
	glm::vec3 cameraTarget;
	glm::vec3 cameraDirection;
	glm::vec3 up;
	glm::vec3 cameraRight;
	glm::vec3 cameraUp;
	glm::vec3 cameraFront;
	const float cameraSpeed = 2.0f; // adjust accordingly
	float m_pitch, m_yaw, m_fov;

public:
	Camera();
	glm::mat4 RotateDemo();
	glm::mat4 GetView();
	glm::mat4 GetProjection();
	void MoveForward(float deltaTime);
	void MoveBackward(float deltaTime);
	void MoveLeft(float deltaTime);
	void MoveRight(float deltaTime);
	void Update(float pitch, float yaw, float fov);
	glm::vec3 GetPos();
};

