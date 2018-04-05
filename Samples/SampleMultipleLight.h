#pragma once
#include "Scene.h"
namespace FMango{
	class SampleMultipleLight:public Scene
	{
	public:
		SampleMultipleLight();
		~SampleMultipleLight();

		bool init();
		void update(float dt);
		void render();
		void resize(unsigned int w, unsigned int h);
	};

}

