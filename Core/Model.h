#pragma once
#include "Drawable.h"
#include "Mesh.h"
namespace FMango{
	class Model :public Drawable
	{
	public:
		Model(void);
		~Model(void);

		Model* load(const char* name);
		void setMesh(Mesh *mesh);
		Mesh* getMesh() const;
		void draw();
		void setShader(const char *vertShader, const char *fragShader);
		//Model* loadObj(const char* name);
		static Model* loadObj(const char* name, bool reCenterMesh, bool loadTex, bool genTang);
		static void trimString(string & str);
		static void generateAveragedNormals(const vector<vec3> & points, vector<vec3> & normals, const vector<int> & faces);
		static void generateTangents(const vector<vec3> & points, const vector<vec3> & normals, const vector<int> & faces, const vector<vec2> & texCoords, vector<vec4> & tangents);
		static void center(vector<vec3> & points);
	private:
		Mesh* m_pMesh;
	};

}