#version 330 core

layout(location = 0) in vec4 position;

uniform vec4 u_color;

out vec4 Pcolor;

void main()
{
	gl_Position = position;
	Pcolor = u_color;
};