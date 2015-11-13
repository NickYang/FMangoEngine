#include "Model.h"

namespace FMango
{
	Model::Model(void)
	{
	}


	Model::~Model(void)
	{
	}

	Model* Model::load(const char* name)
	{
		//TODO:
		return new Model();
	}

	void Model::setMesh(Mesh *mesh)
	{
		m_pMesh = mesh;
	}

	void Model::setShader(const char *vertShader, const char *fragShader)
	{
		m_pShaderProgram = ShaderProgram::create(vertShader, fragShader);
	}

	Mesh* Model::getMesh()const
	{
		return m_pMesh;
	}

	void Model::draw()
	{
		m_pShaderProgram->use();
		m_pMesh->draw();
	}

}