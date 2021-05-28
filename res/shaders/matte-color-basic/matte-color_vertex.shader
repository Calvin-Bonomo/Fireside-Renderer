#version 330 core

layout(location = 0) in vec4 position;

uniform vec4 u_color;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

out vec4 Pcolor;

void main()
{
	gl_Position = u_Projection * u_View * u_Model * position;
	Pcolor = u_color;
};