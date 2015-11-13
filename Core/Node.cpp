#include "Node.h"

namespace FMango{
	Node::Node(void)
	{
	}


	Node::~Node(void)
	{	
		if (m_pModel)
		{
			m_pModel->release();
		}

	}

	void Node::addChild(Node * child)
	{
		m_pChildren.push_back(child);
	}

	void Node::removeChild(Node *child)
	{
		//TODO:性能优化
		vector<Node*>::iterator ite;
		for (ite = m_pChildren.begin(); ite != m_pChildren.end();){
			if (*ite == child)
				ite = m_pChildren.erase(ite);
			else
				++ite;
		}
	}

	void Node::removeAllChildren()
	{

	}

	void Node::setModel(Model *model)
	{
		if (model != NULL)
		{
			m_pModel = model;
			model->addRef();
		}
		else
		{
			if (m_pModel)
			{
				m_pModel->release();
				m_pModel = NULL;
			}
		}
	}

	Model* Node::getModel() const	
	{
		return m_pModel;
	}

}
