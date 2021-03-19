#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 UVcoord;

out vec4 Pcolor;
out vec2 TexCoord;

void main()
{
	gl_Position = position;
	Pcolor = vec4(1.0, 1.0, 1.0, 1.0);
	TexCoord = UVcoord;
};