#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "TestFunctions.h"

#include "ErrorChecking.h"


void TestFunctions::Render1(double time)
{
	/*time = glfwGetTime();*/
	glClearColor(
		static_cast<float>(sin(time) * 0.5 + 0.5)	, 
		static_cast<float>(cos(time) * 0.5 + 0.5)	, 
		0.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT);
}

GLuint TestFunctions::Render2()
{
	GLint error_status;

	const char* vShaderSource =
		"#version 430	 \n"
		"void main(void) \n"
		"{gl_Position = vec4(0.0,0.0,0.0,1.0);}";

	const char* fShaderSource =
		"#version 430	 \n"
		"out vec4 color; \n"
		"void main(void) \n"
		"{color = vec4(0.0,0.0,1.0,1.0);}";								// {	if (gl_FragCoord.x < 295) color = vec4(1.0, 0.0, 0.0, 1.0); else color = vec4(0.0, 0.0, 1.0, 1.0);	} 

	// ---- COMPILE VERTEX
	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, &vShaderSource, NULL);					// ---- Gather and read the shader txt files
	// DEBUG
	glCompileShader(vShader);
	ErrorChecking::checkOpenGLError();								
	
	// ---- Debugging vars
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &error_status);
	if (error_status != GL_TRUE) {
		std::cout << "vertex compilation failed" << std::endl;
		ErrorChecking::printShaderLog(vShader);
	}


	// ---- COMPILE -- FRAG
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShader, 1, &fShaderSource, NULL);					// ---- Gather and read the shader txt files
	glCompileShader(fShader);
	// DEBUG
	ErrorChecking::checkOpenGLError();
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &error_status);
	if (error_status != GL_TRUE) {
		std::cout << "fragment compilation failed" << std::endl;
		ErrorChecking::printShaderLog(fShader);
	}

	// ---- CREATE PROG
	GLuint vfProgram = glCreateProgram();
	glAttachShader(vfProgram, vShader);									// ---- Attach The Shader
	glAttachShader(vfProgram, fShader);	
	glLinkProgram(vfProgram);											// ---- Link the program
	ErrorChecking::checkOpenGLError();									
	// DEBUG
	glGetProgramiv(vfProgram, GL_LINK_STATUS, &error_status);
	if (error_status != GL_TRUE) {
		std::cout << "linking failed\n";
		ErrorChecking::printProgramLog(vfProgram);
	}

	// ---- Detach Shaders
	glDetachShader(vfProgram, vShader);
	glDetachShader(vfProgram, fShader);
	// ---- Delete AFTER LINKING
	glDeleteShader(vShader);
	glDeleteShader(fShader);
	
	return vfProgram;


}
