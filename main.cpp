#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <SDL3_image/SDL_image.h>
#include "glm/vec3.hpp"
#include "SOIL/SOIL.h"

#include <iostream>
#include <stdio.h>

#include "Window.h"
#include "Initialize.h"
#include "Timer.h"
#include "ReadFile.h"

GLFWwindow* window; // create a window
Window _window;

int main(void)
{

	ReadFile::ReadFile("test.txt");


    //std::cout << Timer::GetDateTime() << std::endl;
    //Initialize::initGLFW();
    //Initialize::SetWindowContext();
 
    //_window.DeployWindow(&window);      // load window
    //if (!window) {
    //    return -1;
    //}
    ///* Make the window's context current */
    //glfwMakeContextCurrent(window);

    ///// Glad Loader
    //if (!window) return false;
    //Initialize::initGLAD();
   
    //Initialize::GetGLFWInfo();


  

    ///* Loop until the user closes the window */
    //while (!glfwWindowShouldClose(window))
    //{
    //    /* Render here */
    //    glClear(GL_COLOR_BUFFER_BIT);

    //    /* Swap front and back buffers */
    //    glfwSwapBuffers(window);

    //    /* Poll for and process events */
    //    glfwPollEvents();
    //}

    //glfwTerminate();
    //return 0;




}