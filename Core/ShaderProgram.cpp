#include "ShaderProgram.h"

namespace FMango{

	ShaderProgram::ShaderProgram()
	{
	}


	ShaderProgram::~ShaderProgram()
	{
	}

	ShaderProgram* ShaderProgram::create(const char *vertfile, const char *fragfile, const char* define /*= ""*/)
	{
		ShaderProgram *pShaderProg = new ShaderProgram();
		GLuint vertShader = 0;
		GLuint fragShader = 0;
		if (pShaderProg->compile(vertfile, fragfile, vertShader, fragShader))
			pShaderProg->link(vertShader, fragShader);
		else
		{
			//TODO:
		}
		return pShaderProg;			
	}

	bool ShaderProgram::compile(const char* verfile, const char* fragfile, GLuint &vertShader, GLuint &fragShader)
	{
		GLchar * shaderCode;

		// Load contents of file into shaderCode here?
		ifstream inFile("shader/basic.vert", ifstream::in);
		if (!inFile) {
			fprintf(stderr, "Error opening file: shader/basic.vert\n");
			return false;
		}

		shaderCode = (char *)malloc(10000);
		int i = 0;
		while (inFile.good()) {
			// NOTE: the last character read will be invalid
			int c = inFile.get();
			shaderCode[i++] = c;
		}
		inFile.close();
		shaderCode[--i] = '\0';     // null last character filled (invalid)
		////////////////////////////////////////////

		// Create the shader object
		vertShader = glCreateShader(GL_VERTEX_SHADER);
		if (0 == vertShader) {
			fprintf(stderr, "Error creating vertex shader.\n");
			return false;
		}

		// Load the source code into the shader object
		const GLchar* codeArray[] = { shaderCode };
		glShaderSource(vertShader, 1, codeArray, NULL);
		free(shaderCode); // can be removed from book.

		// Compile the shader
		glCompileShader(vertShader);

		// Check compilation status
		GLint result;
		glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
		if (GL_FALSE == result) {
			fprintf(stderr, "Vertex shader compilation failed!\n");

			GLint logLen;
			glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLen);

			if (logLen > 0) {
				char * log = (char *)malloc(logLen);

				GLsizei written;
				glGetShaderInfoLog(vertShader, logLen, &written, log);

				fprintf(stderr, "Shader log: \n%s", log);

				free(log);
				return false;
			}
		}

		//////////////////////////////////////////////////////
		/////////// Fragment shader //////////////////////////
		//////////////////////////////////////////////////////

		// Load contents of file into shaderCode here?
		ifstream fragFile("shader/basic.frag", ifstream::in);
		if (!fragFile) {
			fprintf(stderr, "Error opening file: shader/basic.frag\n");
			return false;
		}

		shaderCode = (char *)malloc(10000);
		i = 0;
		while (fragFile.good()) {
			int c = fragFile.get();
			shaderCode[i++] = c;
		}
		inFile.close();
		shaderCode[--i] = '\0';
		////////////////////////////////////////////

		// Create the shader object
		fragShader = glCreateShader(GL_FRAGMENT_SHADER);
		if (0 == fragShader) {
			fprintf(stderr, "Error creating fragment shader.\n");
			return false;
		}

		// Load the source code into the shader object
		//const GLchar* codeArray[] = {shaderCode};
		codeArray[0] = shaderCode;
		glShaderSource(fragShader, 1, codeArray, NULL);
		free(shaderCode); // can be removed from book.

		// Compile the shader
		glCompileShader(fragShader);

		// Check compilation status
		//GLint result;
		glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
		if (GL_FALSE == result) {
			fprintf(stderr, "Fragment shader compilation failed!\n");

			GLint logLen;
			glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLen);

			if (logLen > 0) {
				char * log = (char *)malloc(logLen);

				GLsizei written;
				glGetShaderInfoLog(fragShader, logLen, &written, log);

				fprintf(stderr, "Shader log: \n%s", log);

				free(log);
				return false;
			}
		}
		return true;
	}

	bool ShaderProgram::link(GLuint vertShader, GLuint fragShader)
	{
		// Create the program object
		programHandle = glCreateProgram();
		if (0 == programHandle) {
			fprintf(stderr, "Error creating program object.\n");
			return false;
		}

		//TODO:bind order;
		// Bind index 0 to the shader input variable "VertexPosition"
		glBindAttribLocation(programHandle, 0, "VertexPosition");
		// Bind index 1 to the shader input variable "VertexColor"
		glBindAttribLocation(programHandle, 1, "VertexColor");

		// Attach the shaders to the program object
		glAttachShader(programHandle, vertShader);
		glAttachShader(programHandle, fragShader);

		// Link the program
		glLinkProgram(programHandle);

		// Check for successful linking
		GLint status;
		glGetProgramiv(programHandle, GL_LINK_STATUS, &status);
		if (GL_FALSE == status) {

			fprintf(stderr, "Failed to link shader program!\n");

			GLint logLen;
			glGetProgramiv(programHandle, GL_INFO_LOG_LENGTH, &logLen);

			if (logLen > 0) {
				char * log = (char *)malloc(logLen);

				GLsizei written;
				glGetProgramInfoLog(programHandle, logLen, &written, log);

				fprintf(stderr, "Program log: \n%s", log);

				free(log);
				return false;
			}
		}
		GLint activeAttributes;
		glGetProgramiv(programHandle, GL_ACTIVE_ATTRIBUTES, &activeAttributes);
		if (activeAttributes > 0)
		{
			GLint length;
			glGetProgramiv(programHandle, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &length);
			if (length > 0)
			{
				GLchar *attribName = new GLchar[length + 1];
				GLint attribSize;
				GLenum attribType;
				GLint attribLocation;
				for (int i = 0; i < length; i++)
				{
					glGetActiveAttrib(programHandle, i, length, NULL, &attribSize, &attribType, attribName);
					attribName[length] = '\0';
					attribLocation = glGetAttribLocation(programHandle, attribName);
					m_mapAttribLocation[attribName] = attribLocation;
				}
			}
		}


		return true;
	}

	void ShaderProgram::use()
	{
		glUseProgram(programHandle);
	}

	int ShaderProgram::getAttribLocation(const string &name) const
	{
		return m_mapAttribLocation.at(name);
	}

}
