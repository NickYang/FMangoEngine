#include "IndexBuffer.h"

namespace FMango{

	IndexBuffer::IndexBuffer()
	{
	}

	IndexBuffer::IndexBuffer(unsigned int *data, unsigned int size)
		:m_pData(data), m_uSize(size)
	{

	}


	IndexBuffer::~IndexBuffer()
	{
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
