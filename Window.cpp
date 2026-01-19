#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include "Window.h"
// this is a pointer to a pointer
// 
GLFWwindow* Window::DeployWindow(GLFWwindow** win)

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

}