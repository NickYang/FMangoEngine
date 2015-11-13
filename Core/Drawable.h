#pragma once
#include "Ref.h"
namespace FMango{
	class Drawable: public Ref
	{
	public:
		Drawable();
		~Drawable();
		//virtual void OnDrawBegin() = 0;
		//virtual void OnDrawEnd() = 0;
		virtual void draw() = 0;
	};


}

