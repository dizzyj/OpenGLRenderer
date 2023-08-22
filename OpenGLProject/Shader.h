#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include<sstream>
#include "GLErrorManager.h"
#include <unordered_map>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct ShaderProgramSource {
	std::string VertexSource;
	std::string FragmentSource;
};
class Shader
{
private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	//caching for uniforms
	std::unordered_map<std::string,  int> m_UniformLocationCache;
public:
	Shader(const std::string& filepath);
	~Shader();
	void Bind() const;
	void UnBind() const;

	void SetUniformMatrix4fv(const std::string name, int value, glm::mat4 mat);

	//set uniforms
	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float value);
	void SetUniform4f(const std::string name,float v0, float v1, float v2, float v3);
	
private:
	int GetUniformLocation(const std::string& name);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	ShaderProgramSource ParseShader(const std::string& filepath);

};

