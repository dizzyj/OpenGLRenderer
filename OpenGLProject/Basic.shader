#shader vertex
#version 330 core
layout(location = 0) in vec3 apos;
out vec3 texCoords;
uniform mat4 u_Model;
uniform mat4 u_Projection;
uniform mat4 u_View;
void main()
{
	gl_Position = u_Projection * u_View * u_Model * vec4(apos, 1.0f);
	texCoords = vec3(apos.x, apos.y, -apos.z);
};





#shader fragment
#version 330 core
layout(location = 0) out vec4 color;
in vec3 texCoords;
uniform vec4 u_Color;
uniform samplerCube u_Cubemap;
uniform vec3 lightColor;
void main()
{
	
	vec4 frag = texture(u_Cubemap, texCoords);
	//color = vec4(frag.x * lightColor.x,frag.y * lightColor.y,frag.z * lightColor.z, 1);
	color = frag;
	//color = vec4(1, 0, 0, 1);
	//color = vec4(texCoords, 1);
};