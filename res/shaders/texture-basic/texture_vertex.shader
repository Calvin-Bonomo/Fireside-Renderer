#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 UVcoord;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

out vec4 Pcolor;
out vec2 TexCoord;

void main()
{
	gl_Position = u_Projection * u_View * u_Model * position;
	Pcolor = vec4(1.0, 1.0, 1.0, 1.0);
	TexCoord = UVcoord;
};