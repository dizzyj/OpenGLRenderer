#pragma once
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Renderer.h"
#include "Shader.h"
class Light
{
	glm::mat4 transform;
	VertexArray* va;
	VertexBuffer* vb;
	VertexBufferLayout* layout;
	IndexBuffer* ib;
	Renderer renderer;
	Shader* shader;
	float x, y, z;
	glm::vec4 lightColor{1.0, 1.0, 1.0, 1.0};
	glm::vec3 lightPos{ 1.2f, 1.0f, 2.0f };
	unsigned int indices[6 * 6] = {  // note that we start from 0!
			//tri1		//tri 2
			3, 0, 1,	1, 2, 3,	// Front x+
			0, 5, 1,	0, 4, 5,	// right +z
			4, 6, 5,	4, 7, 6,	// back x-
			7, 2, 6,	7, 3, 2,	// left-z
			3, 7, 0,	7, 4, 0,	// fifth square
			6, 2, 1,	6, 1, 5		// sixth square
	};
public:

	Light(float x, float y, float z);
	void Draw(glm::mat4 viewCamera, glm::mat4 projectionCamera);
	glm::vec4 GetColor();
	glm::vec3 GetPosition();
	void UpdatePosition(float x, float y, float z);
};

