#pragma once
#include "Renderer.h"

void Renderer::Draw(VertexArray& va, IndexBuffer& ib, Shader& shader) const{
	va.Bind();
	shader.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount() , GL_UNSIGNED_INT, nullptr));

}

void Renderer::Clear()const {
	GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}