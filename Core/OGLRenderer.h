#pragma once
#include "Renderer.h"

namespace FMango {
class OGLRenderer :
	public Renderer
{
public:
	OGLRenderer();
	~OGLRenderer();

	void Render();
	RENDERER_TYPE getType();
};
}

