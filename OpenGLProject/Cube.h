#pragma once
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Texture_Cube.h"
#include "Renderer.h"
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
enum CubeType
{
	GRASS, CAT, TEST
};
class Cube
{
private:
	glm::mat4 transform;
	VertexArray *va;
	VertexBuffer* vb;
	VertexBufferLayout *layout;
	IndexBuffer *ib;
	Renderer renderer;
	CubeType type;
	Texture_Cube *texture;
	Shader *shader;
	//float x,y,z;
	unsigned int indices[6*6] = {  // note that we start from 0!
			//tri1		//tri 2
			0, 1, 2,	3, 4, 5,	// Front x+
			6, 7, 8,	9, 10, 11,	// right +z
			12, 13, 14,	15, 16, 17,	// back x-
			18, 19, 20,	21, 22, 23,	// left-z
			24, 25, 26,	27, 28, 29,	// fifth square
			30, 31, 32,	33, 34, 35		// sixth square
	};
public:
	
	Cube(CubeType type, float pos_x, float pos_y, float pos_z);
	void Draw(glm::mat4 viewCamera, glm::mat4 projectionCamera);
	void Rotate();
	void SetLight(glm::vec4 light);
	void SetLightPos(glm::vec3 pos);
	void SetCameraPos(glm::vec3 camPos);
};

