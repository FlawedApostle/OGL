#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include "Window.h"
// this is a pointer to a pointer
// 
GLFWwindow* Window::InitWindow(GLFWwindow** win)

{
    /* Create a windowed mode window and its OpenGL context */
    //Set_Window(window);
    printf("setting up window....\n");
    *win = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!win)
    {
        glfwTerminate();
        return nullptr;
    }

    printf("window created !\n");
    /* Make the window's context current - this line is the reason OPENGL will launch*/
    glfwMakeContextCurrent(*win);
    printf("context created !\n");
}

void Window::DisplayWindow(GLFWwindow* window, double time) {
	glClearColor((float)(sin(time) * 0.5 + 0.5), (float)(cos(time) * 0.5 + 0.5), 0.0f, 1.0f);   
    glClear(GL_COLOR_BUFFER_BIT);
}