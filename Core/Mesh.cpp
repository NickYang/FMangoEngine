#include "Base.h"
#include "Mesh.h"	



namespace FMango{
	Mesh::Mesh(void)
	{
	}

	Mesh::Mesh(const vector<VertexData> &vertexList, const vector<int> &indexList)
	{

	}

	Mesh::Mesh(int numVertices, float *points, int numTriangles, int* indices)
	{
	/*	glGenVertexArrays(1, &_vao);
		glBindVertexArray(_vao);
		GLuint buffers[2];
		glGenBuffers(2, buffers);
		glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
		glBufferData(GL_ARRAY_BUFFER, (3 * numVertices)*sizeof(float), points, GL_STATIC_DRAW);
		glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, ((GLubyte *)NULL + (0)));

		glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
		glBufferData(GL_ARRAY_BUFFER, (3*numVertices)*sizeof(float), )
		glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, false, 3, points);
		glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, false, 3, points);

		glBindVertexArray(0);*/
	}

	Mesh::Mesh(VertexBuffer* vertexBuffer, IndexBuffer *IndexBuffer)
		:m_pVertexBuffer(vertexBuffer), m_indexBuffer(IndexBuffer)
	{
		float *pVertexData = m_pVertexBuffer->getVertexData();
		unsigned int *pIndexData = m_indexBuffer->getData();
		VertexFormat *pVertexFormat = m_pVertexBuffer->getVertexFormat();
		unsigned int uCount = m_pVertexBuffer->getVertexCount();
		glGenVertexArrays(1, &m_uVao);
		glBindVertexArray(m_uVao);
		GLuint vbos[2];
		glGenBuffers(2, vbos);
		glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
		glBufferData(GL_ARRAY_BUFFER, pVertexFormat->getSize()*uCount, pVertexData, GL_DYNAMIC_DRAW);
		size_t offset = 0;
		for (unsigned int i = 0; i < pVertexFormat->getElementCount(); i++)
		{
			const VertexFormat::Element& element = pVertexFormat->getElement(i);
			void* pointer = (void*)offset;
			glVertexAttribPointer(element.usage, element.size, GL_FLOAT, false, pVertexFormat->getSize(), pointer);
			glEnableVertexAttribArray(element.usage);
			offset += element.size*sizeof(float);
		}
	
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbos[1]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer->getSize(), pIndexData, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	Mesh::~Mesh(void)
	{
	}

	Mesh* Mesh::Create(const vector<VertexData> &vertexList, const vector<int> &indexList)
	{
		return new Mesh();
	}

	Mesh* Mesh::Create(int numVertices, float *points, int numTriangles, int* indices)
	{
		return new Mesh(numVertices, points, numTriangles, indices);
	}



	void Mesh::draw()
	{
		glBindVertexArray(m_uVao);
		glDrawArrays(GL_TRIANGLES, 0, m_pVertexBuffer->getVertexCount());
	}

	Mesh* Mesh::create(VertexBuffer* vertexBuffer, IndexBuffer *indexBuffer)
	{
		Mesh* mesh = new Mesh(vertexBuffer, indexBuffer);
		return mesh;
	}

}