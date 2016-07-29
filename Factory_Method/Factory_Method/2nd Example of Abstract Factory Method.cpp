#include <iostream>

class Renderer
{
public:
	virtual ~Renderer() {};
	virtual void RenderIt() = 0;
};

class OpenGLRenderer : public Renderer 
{
	void RenderIt() {
		std::cout << "OpenGL render \n";
	}
};

class DirectXRenderer : public Renderer 
{
	void RenderIt() {
		std::cout << "DirectX render \n";
	}
};

#include <string>

class RendererFactory
{
public:
	Renderer *createRenderer(const std::string& type) 
	{
		if(type == "opengl") 
			return new OpenGLRenderer();
		else if(type == "directx") 
			return new DirectXRenderer();
		else return NULL;
	}
};


int main()
{
	RendererFactory *factory = new RendererFactory();
	factory->createRenderer("opengl")->RenderIt();
	factory->createRenderer("directx")->RenderIt();
	return 0;
}