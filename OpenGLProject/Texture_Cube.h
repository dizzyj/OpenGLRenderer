#pragma once
#include <iostream>
#include <vector>
class Texture_Cube 
{
private:
	unsigned int m_RendererID;
	std::vector<std::string> m_FilePaths;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
public:
	Texture_Cube(const std::vector<std::string> paths);
	~Texture_Cube();

	void Bind(unsigned int slot = 0) const;
	void Unbind()const;
	inline int GetWidth()const { return m_Width; }
	inline int GetHeight()const { return m_Height; }
};

