#include "GLFW/glfw3.h"
#include <iostream>
#include "ErrorChecking.h"

// GLSL compilation ERRORS and OpenGL runtime errors
bool ErrorChecking::checkOpenGLError()
{
	bool foundError = false;
	
	int glErr = glGetError();
	while (glErr != GL_NO_ERROR) {
		std::cout << "glError: " << glErr << std::endl;
		foundError = true;
		glErr = glGetError();
	}
	return foundError;
}
