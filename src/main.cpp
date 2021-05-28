#include "fireside/Renderer.h"

class App : fireside::Application 
{
public:
	fireside::VertexArray* vao;
	fireside::VertexBuffer* vbo;
	fireside::ElementArrayBuffer* eab;
	fireside::Material* material;
	fireside::Shader* shader;
	fireside::Texture* texture;
	fireside::Camera* mainCam;
	fireside::Transform* transform;

	App()
	{
		transform = new fireside::Transform();
		transform->SetScale(200, 200);

		mainCam = new fireside::Camera();
		fireside::Renderer2D renderer;
		if (renderer.InitRenderer(600, 600, "Test", *mainCam) == -1)
			return;

		shader = new fireside::Shader("res/shaders/texture-basic/texture_vertex.shader", "res/shaders/texture-basic/texture_fragment.shader");

		texture = new fireside::Texture();
		texture->LoadTexture("res/textures/dirt.jpg");

		material = new fireside::Material(shader);
		//material->AddUniform("u_color", u_Vec4, (void*)new glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
		material->AddUniform("u_tex", u_Tex2D, (void*)texture);

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

		eab = new fireside::ElementArrayBuffer(index, 6 * sizeof(unsigned int), 6);

		vbo->Unbind();
		vao->Unbind();

		renderer.Start(this);
	}

	~App()
	{
		delete vao;
		delete vbo;
		delete eab;
		delete material;
		delete texture;
		delete mainCam;
		delete transform;
	}

	unsigned int Render() override
	{
		fireside::Renderer2D::doRenderCall(fireside::RenderCall{*vao, *eab, *material, *transform}, *mainCam);
		return 1;
	}
};

int main() 
{
	App app;
	return 0;
}