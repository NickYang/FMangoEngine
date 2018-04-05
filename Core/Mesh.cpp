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

	Mesh::Mesh(VertexBuffer* vertexBuffer, IndexBuffer *IndexBuffer, const char *vertShader, const char *fragShader)
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
		glBufferData(GL_ARRAY_BUFFER, pVertexFormat->getTotalSize()*uCount, pVertexData, GL_DYNAMIC_DRAW);
		size_t offset = 0;
		setShader(vertShader, fragShader);
		for (unsigned int i = 0; i < pVertexFormat->getElementCount(); i++)
		{
			const VertexFormat::Element& element = pVertexFormat->getElement(i);
			void* pointer = (void*)offset;
			GLint index;
			switch (element.usage)
			{
			case VertexFormat::POSITION:
				index = m_pShaderProgram->getAttribLocation(VERTEX_ATTRIBUTE_POSITION_NAME);
				break;
			case VertexFormat::COLOR:
				index = m_pShaderProgram->getAttribLocation(VERTEX_ATTRIBUTE_COLOR_NAME);
				break;
			case VertexFormat::NORMAL:
				index = m_pShaderProgram->getAttribLocation(VERTEX_ATTRIBUTE_NORMAL_NAME);
				break;
			case VertexFormat::TANGENT:
				index = m_pShaderProgram->getAttribLocation(VERTEX_ATTRIBUTE_TANGENT_NAME);
				break;
			//TODO:
			case VertexFormat::TEXCOORD0:
				assert(false);
				index = m_pShaderProgram->getAttribLocation(VERTEX_ATTRIBUTE_TEXCOORD_PREFIX_NAME);
				break;
			default:
				index = -1;
				break;
			}
			glVertexAttribPointer(index, element.size, GL_FLOAT, false, pVertexFormat->getTotalSize(), pointer);
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

	void Mesh::setShader(const char *vertShader, const char *fragShader)
	{
		m_pShaderProgram = ShaderProgram::create(vertShader, fragShader);
	}


	void Mesh::draw()
	{
		m_pShaderProgram->use();
		glBindVertexArray(m_uVao);
		glDrawArrays(GL_TRIANGLES, 0, m_pVertexBuffer->getVertexCount());
	}

	Mesh* Mesh::create(VertexBuffer* vertexBuffer, IndexBuffer *indexBuffer, const char *vertShader, const char *fragShader)
	{
		Mesh* mesh = new Mesh(vertexBuffer, indexBuffer, vertShader, fragShader);
		return mesh;
	}

}