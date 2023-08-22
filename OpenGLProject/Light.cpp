#include "Light.h"

Light::Light(float x, float y, float z)
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
	ib = new IndexBuffer(indices, 6 * 6);
	ib->Bind();


	std::vector<std::string> paths;
	shader = new Shader("Light.shader");
	shader->Bind();
	//Uniforms
	transform = glm::mat4(1.0f);
	transform = glm::translate(transform, lightPos);
	transform = glm::scale(transform, glm::vec3(0.2f));
	shader->SetUniformMatrix4fv("u_Model", 1, transform);
	shader->UnBind();
}

void Light::Draw(glm::mat4 viewCamera, glm::mat4 projectionCamera)
{
	shader->Bind();
	shader->SetUniformMatrix4fv("u_View", 1, viewCamera);
	shader->SetUniformMatrix4fv("u_Projection", 1, projectionCamera);
	renderer.Draw(*va, *ib, *shader);
}
