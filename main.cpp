
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "SDL3_image/SDL_image.h"       // image SDL
#include "SOIL/SOIL.h"                  // image openGL
#include "glm/vec3.hpp"                 // math
#include "TOL/tiny_obj_loader.h"        // fbx loader - tinyOBJ - header only
#include "ASSIMP/config.h"              // fbx - assimp static lib
#include "ASSIMP/revision.h"            // fbx - assimp static lib
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

	//ReadFile::ReadFile("test.txt");


    std::cout << Timer::GetDateTime() << std::endl;
    Initialize::initGLFW();
    Initialize::SetWindowContext();
 
    _window.InitWindow(&window);      // load window
    if (!window) {
        return -1;
    }


    /// Glad Loader
    if (!window) return false;
    Initialize::initGLAD();
   
    Initialize::GetDriveInfo();


  

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
		_window.DisplayWindow(window, glfwGetTime());
        /* Render here */
        double time = glfwGetTime();
        glClearColor(static_cast<float>(sin(time) * 0.5 + 0.5), static_cast<float>(cos(time) * 0.5 + 0.5), 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }


    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;




}