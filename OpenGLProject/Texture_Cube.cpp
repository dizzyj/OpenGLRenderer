#include "Texture_Cube.h"
#include "stb_image.h"
#include "GLErrorManager.h"
Texture_Cube::Texture_Cube(const std::vector<std::string> paths) :m_RendererID(0), m_FilePaths(paths), m_LocalBuffer(nullptr), m_Width(0), m_Height(0), m_BPP(0)
{
	//create and bind texture
	GLCall(glGenTextures(1, &m_RendererID));
	GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, m_RendererID));
	//load 
	for (unsigned int i = 0; i < paths.size(); i++) {
		stbi_set_flip_vertically_on_load(false);
		m_LocalBuffer = stbi_load(paths[i].c_str(), &m_Width, &m_Height, &m_BPP, 0); // desired channels RGBA
		if (m_LocalBuffer) {
			GLCall(glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer));
		}
		else {
			std::cout << "Failed to load texture" << std::endl;
			if (stbi_failure_reason())
				std::cout << stbi_failure_reason();
		}
	}
	// set texture parameters
	GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
	GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
	GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	GLCall(glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE));
	//unbind texture
	GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, 0));

	if (m_LocalBuffer) {
		stbi_image_free(m_LocalBuffer);
		//std::cout << "Freeing Local Buffer" << std::endl;
	}
}

Texture_Cube::~Texture_Cube()
{
	//TODO: number of textures
	GLCall(glDeleteTextures(6, &m_RendererID));
}

void Texture_Cube::Bind(unsigned int slot) const
{
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));
	GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, m_RendererID));
}

void Texture_Cube::Unbind() const
{
	GLCall(glBindTexture(GL_TEXTURE_CUBE_MAP, 0));
}
