#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "TestFunctions.h"

#include "ErrorChecking.h"

TestFunctions::~TestFunctions()
{
}

void TestFunctions::Render1(double time)
{
	/*time = glfwGetTime();*/
	glClearColor(static_cast<float>(sin(time) * 0.5 + 0.5), static_cast<float>(cos(time) * 0.5 + 0.5), 0.0f, 1.0f);
}

GLuint TestFunctions::Render2()
{

	const char* vShaderSource =
		"#version 430	 \n"
		"void main(void) \n"
		"{gl_Position = vec4(0.0,0.0,0.0,1.0);}";

	const char* fShaderSource =
		"#version 430	 \n"
		"out vec4 color; \n"
		"void main(void) \n"
		"{color = vec4(0.0,0.0,1.0,1.0);}";

	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vShader, 1, &vShaderSource, NULL);
	glShaderSource(fShader, 1, &fShaderSource, NULL);
	glCompileShader(vShader);
	glCompileShader(fShader);

	GLuint vfProgram = glCreateProgram();
	glAttachShader(vfProgram, vShader);
	glAttachShader(vfProgram, fShader);
	glLinkProgram(vfProgram);

	return vfProgram;


}
