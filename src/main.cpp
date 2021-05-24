#include "fireside/Renderer.h"

class App : fireside::Application 
{
public:
	std::shared_ptr<fireside::VertexArray> vao;
	std::shared_ptr<fireside::VertexBuffer> vbo;
	std::shared_ptr<fireside::ElementArrayBuffer> eab;
	std::shared_ptr<fireside::Material> material;
	fireside::Shader *shader;

	App() 
	{
		fireside::Renderer2D renderer;
		renderer.InitRenderer(400, 400, "Test");
		shader = new fireside::Shader("res/shaders/matte-color-basic/matte-color_vertex.shader", "res/shaders/matte-color-basic/matte-color_fragment.shader");

		fireside::Texture texture = fireside::Texture();
		texture.CreateTexture("res/textures/dirt.jpg");

		material = std::make_shared<fireside::Material>(fireside::Material(shader));
		material->AddUniform("u_color", u_Vec4, (void*)new glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));

		vao = std::make_shared<fireside::VertexArray>(fireside::VertexArray());
		vao->Bind();

		float points[]
		{
			-0.5f,  0.5f,    0.0f,  1.0f, // Top-right
			 0.5f,  0.5f,    1.0f,  1.0f, // Top-left
			 0.5f, -0.5f,    1.0f,  0.0f, // Bottom-left
			-0.5f, -0.5f,    0.0f,  0.0f  // Bottom-right
		};
		vbo = std::make_shared<fireside::VertexBuffer>(fireside::VertexBuffer(points, 4 * 4 * sizeof(float)));
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

		eab = std::make_shared<fireside::ElementArrayBuffer>(fireside::ElementArrayBuffer(index, 6 * sizeof(unsigned int), 6));

		vbo->Unbind();
		vao->Unbind();

		renderer.Start(this);
	}

	~App()
	{
	}

	unsigned int Render() override
	{
		glm::mat4x4* camMat = new glm::mat4x4();
		fireside::Renderer2D::doRenderCall(fireside::RenderCall{vao, eab}, *camMat);
		delete camMat;
		return 1;
	}
};

int main() 
{
	App app;
	return 0;
}