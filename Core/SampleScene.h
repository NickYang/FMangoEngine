#pragma once
#include "Base.h"
#include "Scene.h"
#include "ShaderProgram.h"

namespace FMango{

	class SampleScene :
		public Scene
	{
	public:
		SampleScene();
		~SampleScene();

		bool init();
		void update(float dt);
		void render();
		void resize(unsigned int w, unsigned int h);
	private:
	};

}
