#pragma once
#include "Scene.h"

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
