#include "SampleMultipleLight.h"

namespace FMango{

	SampleMultipleLight::SampleMultipleLight()
	{
	}


	SampleMultipleLight::~SampleMultipleLight()
	{
	}

	bool SampleMultipleLight::init()
	{
		Node* node = new Node();
		Model *pModel = Model::loadObj("../Bin/Debug/res/pig_triangulated.obj", true, false, false);
		node->setModel(pModel);
		addChild(node);
		return true;
	}

	void SampleMultipleLight::update(float dt)
	{

	}

	void SampleMultipleLight::render()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		std::vector<Node*>::iterator ite;
		for (ite = m_pChildren.begin(); ite != m_pChildren.end(); ++ite)
		{
			Node* node = *ite;
			Model* model = node->getModel();
			if (model != NULL)
			{
				model->draw();
			}
		}
	}

	void SampleMultipleLight::resize(unsigned int w, unsigned int h)
	{

	}

}