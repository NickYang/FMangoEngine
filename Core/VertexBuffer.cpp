#include "VertexBuffer.h"

namespace FMango{
	void VertexFormat::getElements(const std::vector<Element>& elements)
	{

	}

	void VertexFormat::pushElement(Element element)
	{
		m_vecElement.push_back(element);
	}

	unsigned int VertexFormat::getTotalSize()
	{
		unsigned int size = 0;
		for (unsigned int i = 0; i < m_vecElement.size(); i++)
		{
			Element e = m_vecElement.at(i);
			//TODO:not alway float type, maybe int or other;
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

	VertexBuffer::VertexBuffer(const vector<vec3> &vecPos, 
		const vector<vec3> &vecNormal, 
		const vector <vec2> &vecUV, 
		const vector<vec4> &vecTengent)
	{
		m_pVertexFormat = new VertexFormat();
		VertexFormat::Element ePos;
		ePos.usage = VertexFormat::POSITION;
		ePos.size = 3;
		m_pVertexFormat->pushElement(ePos);

		if (vecNormal.size() > 0)
		{
			VertexFormat::Element eNormal;
			eNormal.usage = VertexFormat::NORMAL;
			eNormal.size = 3;
			m_pVertexFormat->pushElement(eNormal);
		}

		if (vecTengent.size() > 0)
		{
			VertexFormat::Element eTangent;
			eTangent.usage = VertexFormat::TANGENT;
			eTangent.size = 4;
			m_pVertexFormat->pushElement(eTangent);
		}

		if (vecUV.size() > 0)
		{
			VertexFormat::Element eUV;
			eUV.usage = VertexFormat::TEXCOORD0;
			eUV.size = 2;
			m_pVertexFormat->pushElement(eUV);
		}

		m_pData = new float[m_pVertexFormat->getTotalSize()*vecPos.size()];
		printf("%d,%d\n", m_pVertexFormat->getTotalSize(), vecPos.size());
		vector<vec3>::const_iterator it;
		unsigned int i = 0;
		unsigned int j = 0;
		for (it = vecPos.cbegin(); it != vecPos.cend(); it++)
		{
			vec3 pos = *it;
			m_pData[i++] = pos.x;
			m_pData[i++] = pos.y;
			m_pData[i++] = pos.z;

			if (vecNormal.size() > 0)
			{
				vec3 normal = vecNormal.at(j);
				m_pData[i++] = normal.x;
				m_pData[i++] = normal.y;
				m_pData[i++] = normal.z;
			}
			if (vecTengent.size() > 0)
			{
				vec4 tangent = vecTengent.at(j);
				m_pData[i++] = tangent.x;
				m_pData[i++] = tangent.y;
				m_pData[i++] = tangent.z;
				m_pData[i++] = tangent.w;
			}

			if (vecUV.size() > 0)
			{
				vec2 uv = vecUV.at(j);
				m_pData[i++] = uv.x;
				m_pData[i++] = uv.y;
			}
			j++;
		}
	}

	VertexBuffer::~VertexBuffer()
	{
		if (m_pData)
		{
			delete m_pData;
			m_pData = NULL;
		}
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