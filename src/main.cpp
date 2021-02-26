#include "Renderer.h"

class App : fireside::Application 
{
public:
	fireside::VertexArray* vao;
	fireside::VertexBuffer* vbo;
	fireside::ElementArrayBuffer* eab;
	fireside::Shader* shader;
	fireside::Texture* texture;

	App() 
	{
		fireside::Renderer2D renderer;
		renderer.InitRenderer(400, 400, "Test");

		shader = new fireside::Shader("res/shaders/matte_color_vertex.shader", "res/shaders/matte_color_fragment.shader");

		texture = new fireside::Texture();
		texture->CreateTexture("res/textures/dirt.jpg");

		vao = new fireside::VertexArray();
		vao->Bind();

		float points[]
		{
			-0.5f,  0.5f,    0.0f,  1.0f, // Top-right
			 0.5f,  0.5f,    1.0f,  1.0f, // Top-left
			 0.5f, -0.5f,    1.0f,  0.0f, // Bottom-left
			-0.5f, -0.5f,    0.0f,  0.0f  // Bottom-right
		};

		vbo = new fireside::VertexBuffer(points, 4 * 4 * sizeof(float));
		vbo->Bind();

		fireside::VertexLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		vao->AddLayout(layout);

		unsigned int index[] =
		{
			0, 1, 2,
			0, 2, 3
		};

		eab = new fireside::ElementArrayBuffer(index, 6 * sizeof(unsigned int));

		vbo->Unbind();
		vao->Unbind();

		renderer.Start(this);
	}

	~App()
	{
		delete vao;
		delete vbo;
		delete eab;
		delete shader;
		delete texture;
	}

	unsigned int Render() override
	{
		shader->Bind();
		texture->Bind();
		vao->Bind();
		eab->Bind();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		vao->Unbind();
		eab->Unbind();
		shader->Unbind();
		texture->Unbind();
		return 1;
	}
};

int main() 
{
	App app;
	return 0;
}