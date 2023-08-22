#include "Cube.h"
#include <iostream>
Cube::Cube(CubeType type, float x, float y, float z): type(type)
{
	float vertices[3 * 8] = {
		//PositionCoords	//textureCoords
		 0.5f,  0.5f, 0.5f, // top right
		 0.5f, -0.5f, 0.5f,	// bottom right
		-0.5f, -0.5f, 0.5f, // bottom left
		-0.5f,  0.5f, 0.5f, // top left 

		 0.5f,  0.5f, -0.5f,	// top right back
		 0.5f, -0.5f, -0.5f,	// bottom right back
		-0.5f, -0.5f, -0.5f, // bottom left back
		-0.5f,  0.5f, -0.5f, // top left back
	};
	
	layout = new VertexBufferLayout;
	vb = new VertexBuffer(vertices, 8 * 3 * sizeof(float));
	layout->Push<float>(3);
	va = new VertexArray();
	va->AddBuffer(*vb, *layout);
	ib =  new IndexBuffer(indices, 6 * 6);
	ib->Bind();


	std::vector<std::string> paths;
	shader = new Shader("Basic.shader");
	switch (type) {
	case CubeType::GRASS:
	case CubeType::CAT:
		paths.push_back(".\\res\\textures\\cat1.png");
		paths.push_back(".\\res\\textures\\cat2.png");
		paths.push_back(".\\res\\textures\\cat3.png");
		paths.push_back(".\\res\\textures\\cat4.png");
		paths.push_back(".\\res\\textures\\cat5.png");
		paths.push_back(".\\res\\textures\\cat6.png");
		break;
	}
	texture = new Texture_Cube(paths);
	shader->Bind();
	//Uniforms
	shader->SetUniform1i("u_Cubemap", 0);
	transform = glm::mat4(1.0f);
	transform = glm::translate(transform, glm::vec3(x,y,z));
	shader->SetUniformMatrix4fv("u_Model", 1, transform);
	// note that we're translating the scene in the reverse direction of where we want to move
	shader->UnBind();
}
void Cube::Draw(glm::mat4 viewCamera, glm::mat4 projectionCamera) {

	texture->Bind();
	shader->Bind();
	shader->SetUniformMatrix4fv("u_View", 1, viewCamera);
	shader->SetUniformMatrix4fv("u_Projection", 1, projectionCamera);
	renderer.Draw(*va, *ib, *shader);
}

void Cube::Rotate()
{
	shader->Bind();
	transform = glm::rotate(transform, glm::radians(0.5f), glm::vec3(0.3, 0.5, 1.0));
	shader->SetUniformMatrix4fv("u_Model", 1, transform);
}
