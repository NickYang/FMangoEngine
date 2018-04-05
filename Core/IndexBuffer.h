#pragma once
#include "Base.h"
#include "Ref.h"
namespace FMango{
	class IndexBuffer :
		public Ref
	{
	public:
		IndexBuffer();
		IndexBuffer(unsigned int *data, unsigned int size);
		IndexBuffer(const vector<int> &vecFaces);
		~IndexBuffer();

		void setData(int *data);
		void setCount(unsigned int size);

		unsigned int* getData() const;
		unsigned int getCount() const;
		unsigned int getSize() const;
	private:
		unsigned int *m_pData;
		unsigned int m_uSize;
	};

}

