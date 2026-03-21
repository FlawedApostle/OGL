#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include "Window.h"

Window::Window(int width, int height, const char* title)                            // Create Load Window
{
    printf("setting up Window....\n");
    win = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!win) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
    }

    glfwMakeContextCurrent(win);
}

// ------ [DEPRECATED] NOT USING FOR NOW - THE BUFFER RENDER CLEAN UP DRAW CALLS && THE glfwPOLLEVENTS - BOTH ARE INSIDE THE MAIN.CPP WHILE LOOP
void Window::Update()                                                               // UPDATE LOOP FOR WINDOW
    {
        glfwSwapBuffers(win);
        glfwPollEvents();
    }

// ----------- DEBUGGER 
/* pointer to a pointer
// - when user creates *window this function takes the raw value dereferences it to update it */
GLFWwindow* Window::InitWindow(GLFWwindow** win)
{
    /* Create a windowed mode window and its OpenGL context */
    //Set_Window(window);
    printf("setting up initWindow....\n");
    *win = glfwCreateWindow(640, 480, "Init Window", NULL, NULL);
    if (!win)
    {
        glfwTerminate();
        return nullptr;
    }

    printf("initWindow Successful !\n");
    /* Make the window's context current - this line is the reason OPENGL will launch*/
    glfwMakeContextCurrent(*win);
    printf("initWindo context Successful !\n");
}
