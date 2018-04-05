#pragma once

#include "Scene.h"
namespace FMango{

	class PostProcessing :
		public Scene
	{
	public:
		PostProcessing();
		~PostProcessing();

		bool init();
	};
}
