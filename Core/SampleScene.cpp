#include "SampleScene.h"
#include "Model.h"
#include "Mesh.h"
#include <fstream>
using namespace std;
namespace FMango
{

	SampleScene::SampleScene()
	{
	}


	SampleScene::~SampleScene()
	{

	}


	bool SampleScene::init()
	{
		Node* node = new Node();
		Model* model = new Model();
		model->setShader("shader/basic.vert", "shader/basic.frag");
		float data[] = {
			-0.8f, -0.8f, 0.0f,
			1.0f, 0.0f, 0.0f,
			0.8f, -0.8f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 0.8f, 0.0f,
			0.0f, 0.0f, 1.0f };
		unsigned int indices[] = { 0, 1, 2 };
		VertexFormat* pVertexFormat = new VertexFormat();
		VertexFormat::Element ePos = VertexFormat::Element();
		ePos.size = 3;
		ePos.usage = VertexFormat::POSITION;
		VertexFormat::Element eColor = VertexFormat::Element();
		eColor.size = 3;
		eColor.usage = VertexFormat::COLOR;

		pVertexFormat->pushElement(ePos);
		pVertexFormat->pushElement(eColor);

		VertexBuffer *pVetexBuffer = new VertexBuffer(pVertexFormat, data, sizeof(data)/sizeof(float)/(ePos.size+ eColor.size));
		IndexBuffer *pIndexBuffer = new IndexBuffer(indices, 3);
		Mesh * mesh = Mesh::create(pVetexBuffer, pIndexBuffer);

		model->setMesh(mesh);
		node->setModel(model);
		
		addChild(node);
		return true;
	}

	void SampleScene::update(float dt)
	{

	}

	void SampleScene::render()
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

	void SampleScene::resize(unsigned int w, unsigned int h)
	{

	}

}
