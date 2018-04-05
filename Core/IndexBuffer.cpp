#include "IndexBuffer.h"

namespace FMango{

	IndexBuffer::IndexBuffer()
	{
	}

	IndexBuffer::IndexBuffer(unsigned int *data, unsigned int size)
		:m_pData(data), m_uSize(size)
	{

	}

	IndexBuffer::IndexBuffer(const vector<int> &vecFaces)
	{
		m_uSize = vecFaces.size();
		m_pData = new unsigned int[m_uSize];
		vector<int>::const_iterator it;
		unsigned int i = 0;
		for (it = vecFaces.cbegin(); it != vecFaces.cend(); it++)
		{
			m_pData[i++] = (unsigned int)*it;
		}
	}

	IndexBuffer::~IndexBuffer()
	{
		if (m_pData)
		{
			delete m_pData;
			m_pData = NULL;
		}
	}

	void IndexBuffer::setData(int *data)
	{

	}

	void IndexBuffer::setCount(unsigned int size)
	{

	}

	unsigned int* IndexBuffer::getData() const
	{
		return m_pData;
	}

	unsigned int IndexBuffer::getCount() const
	{
		return m_uSize;
	}

	unsigned int IndexBuffer::getSize() const
	{
		return m_uSize*sizeof(int);
	}
}
