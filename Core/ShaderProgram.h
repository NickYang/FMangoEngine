#pragma once
#include "Base.h"
#include "Ref.h"

namespace FMango{

	class ShaderProgram :
		public Ref
	{
	public:
		static ShaderProgram* create(const char *vertfile, const char *fragfile, const char* define = "");
		void use();
	protected:
		ShaderProgram();
		//ShaderProgram(const char *vertfile, const char *fragfile, const char* define);
		~ShaderProgram();

	private:
		bool compile(const char* verfile, const char* fragfile, GLuint &vertShader, GLuint &fragShader);
		bool link(GLuint vertShader, GLuint fragShader);

	private:
		GLuint programHandle;
	};




}
