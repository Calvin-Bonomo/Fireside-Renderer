#version 330 core

layout(location = 0) out vec4 color;

in vec4 Pcolor;
in vec2 TexCoord;

uniform sampler2D tex;

void main()
{
	color = texture(tex, TexCoord);
};