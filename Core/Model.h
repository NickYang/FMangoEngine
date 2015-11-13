#pragma once
#include "Drawable.h"
#include "Mesh.h"
#include "ShaderProgram.h"
namespace FMango{
	class Model :public Drawable
	{
	public:
		Model(void);
		~Model(void);

		Model* load(const char* name);
		void setMesh(Mesh *mesh);
		Mesh* getMesh() const;
		void draw();
		void setShader(const char *vertShader, const char *fragShader);
	private:
		Mesh* m_pMesh;
		ShaderProgram* m_pShaderProgram;

	};

}