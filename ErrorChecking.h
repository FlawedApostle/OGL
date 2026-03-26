#pragma once
namespace ErrorChecking
{
	 bool checkOpenGLError();
	 void printShaderLog(GLuint shader);
	 void printProgramLog(int prog);

	 bool CheckShaderCompile(GLuint shader);

};

