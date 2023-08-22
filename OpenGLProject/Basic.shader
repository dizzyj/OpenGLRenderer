#shader vertex
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
out vec3 texCoords;
out vec3 Normal;
out vec3 FragPos;
uniform mat4 u_Model;
uniform mat4 u_Projection;
uniform mat4 u_View;
void main()
{
	gl_Position = u_Projection * u_View * u_Model * vec4(aPos, 1.0f);
	Normal = aNormal;
	texCoords = vec3(aPos.x, aPos.y, -aPos.z);
	FragPos = vec3(u_Model * vec4(aPos, 1.0f));
};





#shader fragment
#version 330 core
layout(location = 0) out vec4 color;
in vec3 texCoords;
in vec3 Normal;
in vec3 FragPos;
uniform vec4 u_Color;
uniform samplerCube u_Cubemap;
uniform vec3 u_LightPos;
uniform vec4 u_LightColor;
uniform vec3 u_ViewPos;
void main()
{
	float specularStrength = 0.5;
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(u_LightPos - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec4 diffuse = vec4((diff * u_LightColor));
	
	float ambientStrength = 0.1;
	vec4 ambient = vec4(ambientStrength * u_LightColor.x, ambientStrength * u_LightColor.y, ambientStrength * u_LightColor.z, 1);
	vec4 frag = texture(u_Cubemap, texCoords);
	vec3 viewDir = normalize(u_ViewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec4 specular = specularStrength * spec * u_LightColor;

	color = frag * (ambient + diffuse + specular) ;

};