#pragma once
#include "Base.h"
#include <vector>
#include "Drawable.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
using namespace std;
namespace FMango{
	class Mesh:Drawable
	{
		struct Position
		{
			float x;
			float y;
			float z;
		};
		struct Color
		{
			float r;
			float g;
			float b;
			float a;
		};
		struct VertexData
		{
			Position pos;
			Color color;
		};
	public:
		static Mesh* Create(const vector<VertexData> &vertexList,	const vector<int> &indexList);
		static Mesh* Create(int numVertices, float *points, int numTriangles, int* indices);
		static Mesh* create(VertexBuffer* vertexBuffer, IndexBuffer *IndexBuffer);
		void draw();
	protected:
		Mesh(void);
		Mesh(const vector<VertexData> &vertexList, const vector<int> &indexList);
		Mesh(int numVertices, float *points, int numTriangles, int* indices);
		Mesh(VertexBuffer* vertexBuffer, IndexBuffer *IndexBuffer);
		~Mesh(void);

	private:
		VertexBuffer *m_pVertexBuffer;
		IndexBuffer *m_indexBuffer;
		GLuint m_uVao;
	};

}

