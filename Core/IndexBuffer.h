#pragma once
#include "Ref.h"
namespace FMango{
	class IndexBuffer :
		public Ref
	{
	public:
		IndexBuffer();
		IndexBuffer(unsigned int *data, unsigned int size);

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

