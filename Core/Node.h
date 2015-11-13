#pragma once
#include "Ref.h"
#include "Model.h"
namespace FMango{
	class Node : public Ref
	{
	public:
		Node(void);
		virtual ~Node(void);

		void addChild(Node * child);
		void removeChild(Node *child);
		void removeAllChildren();

		void setModel(Model *model);
		Model* getModel() const;
	protected:
		Model *m_pModel;
		std::vector<Node*> m_pChildren;
	};
}
