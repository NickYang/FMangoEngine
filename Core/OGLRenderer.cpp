#include "OGLRenderer.h"

namespace FMango{
OGLRenderer::OGLRenderer()
{
}


OGLRenderer::~OGLRenderer()
{
}

void OGLRenderer::Render()
{

}

Renderer::RENDERER_TYPE OGLRenderer::getType()
{
	return RENDERER_TYPE::OPENGL;
}

}