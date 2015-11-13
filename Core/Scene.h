#pragma once
#include <vector>
#include "Node.h"
namespace FMango{
	class Scene :
		public Node
	{
	public:
		Scene();
		virtual ~Scene();

		//static Scene* create();
		virtual bool init() = 0;
		virtual void render() = 0;
		virtual void resize(unsigned int w, unsigned int h) = 0;
		virtual void update(float dt) = 0;
	};


}
