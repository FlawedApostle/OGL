#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <stdio.h>

#include "Window.h"
#include "Initialize.h"
#include "Timer.h"

#include "glm/vec3.hpp"
#include "SOIL/SOIL.h"

//#include <glad/glad.h>
GLFWwindow* window;
Window _window;

int main(void)
{
    
    std::cout << Timer::GetDateTime() << std::endl;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    Initialize::initGLFW();
  

    //_initialize.initGLFW();
    _window.DeployWindow(&window);
    if (!window)
    {
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);


    /// Glad Loader
    if (!window) return false;
    Initialize::initGLAD();
   

    /// have to call after glfwMake context
   // GLenum err = glewInit();
   // if (GLEW_OK != err){
   //     fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
   // }
   //// Have to run after  glewInit() !
   // printf("Status: GLEW OK !\n");
   // fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
  

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;




}