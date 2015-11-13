#include "VertexBuffer.h"

namespace FMango{
	void VertexFormat::getElements(const std::vector<Element>& elements)
	{

	}

	void VertexFormat::pushElement(Element element)
	{
		m_vecElement.push_back(element);
	}

	unsigned int VertexFormat::getSize()
	{
		unsigned int size = 0;
		for (unsigned int i = 0; i < m_vecElement.size(); i++)
		{
			Element e = m_vecElement.at(i);
			size += e.size*sizeof(float);
		}
		return size;
	}

	const VertexFormat::Element& VertexFormat::getElement(unsigned int i) const
	{
		return m_vecElement.at(i);
	}

	unsigned int VertexFormat::getElementCount()
	{
		return m_vecElement.size();
	}

	VertexBuffer::VertexBuffer()
	{
	}

	VertexBuffer::VertexBuffer(VertexFormat *format, float *data, unsigned int vertexCount)
		:m_pVertexFormat(format), m_pData(data), m_uCount(vertexCount)
	{

	}

	VertexBuffer::~VertexBuffer()
	{
	}

	void VertexBuffer::setVertexFormat(VertexFormat *format)
	{

	}

	void VertexBuffer::setVertexCount(unsigned int VertexCount)
	{

	}

	void VertexBuffer::setVertexData(float *data)
	{

	}

	VertexFormat* VertexBuffer::getVertexFormat() const
	{
		return m_pVertexFormat;
	}

	float* VertexBuffer::getVertexData() const
	{
		return m_pData;
	}

	unsigned int VertexBuffer::getVertexCount() const
	{
		return m_uCount;
	}

}