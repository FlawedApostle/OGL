#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "TestFunctions.h"

#include "ErrorChecking.h"

TestFunctions::~TestFunctions()
{
	//if (vShader == true) { glDeleteShader(vShader); }
	//if (fShader == true) { glDeleteShader(fShader); }
	
}

void TestFunctions::Render1(double time)
{
	/*time = glfwGetTime();*/
	glClearColor(static_cast<float>(sin(time) * 0.5 + 0.5), static_cast<float>(cos(time) * 0.5 + 0.5), 0.0f, 1.0f);
}

GLuint TestFunctions::Render2()
{
	// ---- Debugging vars
	GLint vertCompiled;
	GLint fragCompiled;
	GLint linked;

	const char* vShaderSource =
		"#version 430	 \n"
		"void main(void) \n"
		"{gl_Position = vec4(0.0,0.0,0.0,1.0);}";

	const char* fShaderSource =
		"#version 430	 \n"
		"out vec4 color; \n"
		"void main(void) \n"
		"{color = vec4(0.0,0.0,1.0,1.0);}";								// {	if (gl_FragCoord.x < 295) color = vec4(1.0, 0.0, 0.0, 1.0); else color = vec4(0.0, 0.0, 1.0, 1.0);	} 

	// ---- Create the shader(s)
	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

	// ---- Gather and read the shader txt files
	glShaderSource(vShader, 1, &vShaderSource, NULL);
	glShaderSource(fShader, 1, &fShaderSource, NULL);
	
	// ---- Compile -- VERT
	glCompileShader(vShader);
	ErrorChecking::checkOpenGLError();									// debug
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertCompiled);
	if (vertCompiled != 1) {
		std::cout << "vertex compilation failed" << std::endl;
		ErrorChecking::printShaderLog(vShader);
	}
	// ---- Compile -- FRAG
	glCompileShader(fShader);
	ErrorChecking::checkOpenGLError();									// debug
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &fragCompiled);
	if (fragCompiled != 1) {
		std::cout << "vertex compilation failed" << std::endl;
		ErrorChecking::printShaderLog(fShader);
	}


	GLuint vfProgram = glCreateProgram();

	// ---- Attach The Shader
	glAttachShader(vfProgram, vShader);
	glAttachShader(vfProgram, fShader);
	
	// ---- Link the program
	glLinkProgram(vfProgram);
	ErrorChecking::checkOpenGLError();									// debug
	glGetProgramiv(vfProgram, GL_LINK_STATUS, &linked);
	if (linked != 1) {
		std::cout << "linking failed" << std::endl;
		ErrorChecking::printProgramLog(vfProgram);
	}

	

	return vfProgram;


}
