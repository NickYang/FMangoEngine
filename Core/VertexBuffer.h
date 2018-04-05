#pragma once
#include "Base.h"
#include "Ref.h"

namespace FMango{
	class VertexFormat
	{	
	public:
		enum Usage
		{
			POSITION = 0,
			COLOR = 1,
			NORMAL = 2,
			TANGENT = 3,
			TEXCOORD0 = 4,
		};
		struct Element
		{
			Usage usage;
			unsigned int size;
		};

		void pushElement(Element element);
		void getElements(const std::vector<Element>& elements);
		const Element& getElement(unsigned int i) const;
		unsigned int getTotalSize();
		unsigned int getElementCount();

	private:
		std::vector<Element> m_vecElement;
	};
	class VertexBuffer :
		public Ref
	{
	public:
		VertexBuffer();
		VertexBuffer(VertexFormat *format, float *data, unsigned int vertexCount);
		VertexBuffer(const vector<vec3> &vecPos, 
			const vector<vec3> &vecNormal, 
			const vector <vec2> &vecUV, 
			const vector<vec4> &vecTengent);
		~VertexBuffer();

		void setVertexFormat(VertexFormat *format);
		void setVertexCount(unsigned int VertexCount);
		void setVertexData(float *data);

		VertexFormat* getVertexFormat() const;
		float* getVertexData() const;
		unsigned int getVertexCount() const;

	private:
		float* m_pData;
		unsigned int m_uCount;
		VertexFormat* m_pVertexFormat;
	};
}

